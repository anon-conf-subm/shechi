#include "consecutive_matmul.h"
#include "../helpers/utils.h"

namespace sequre {

using namespace codon::ir;

void parseConsecutiveMatmulArgs( Value *instruction, std::vector<Value *> &args ) {
    // This procedure assumes that instruction is a consecutive matmul
    auto usedValues = instruction->getUsedValues();

    for ( auto i = 0; i < 2; ++i ) {
        auto *usedValue = usedValues[i];
        if ( isCallOfName(usedValue, Module::MATMUL_MAGIC_NAME) )
            parseConsecutiveMatmulArgs(usedValue, args);
        else
            args.push_back(usedValue);
    }
}

bool transformSingleOrderedMatmul( Value *instruction, std::set<Value *> &visited, Value *mpcValue) {
    auto *matmulInstruction = findCallByName(instruction, Module::MATMUL_MAGIC_NAME, visited);
    if ( !matmulInstruction ) return false;

    auto isConsecutive = false;
    for ( auto *usedValue : matmulInstruction->getUsedValues() )
        if ( isCallOfName(usedValue, Module::MATMUL_MAGIC_NAME) ) {
            isConsecutive = true;
            break;
        }
    if ( !isConsecutive ) return false;

    auto *M = matmulInstruction->getModule();
    std::vector<Value *> matmulArgs;
    parseConsecutiveMatmulArgs( matmulInstruction, matmulArgs);

    if ( matmulArgs.empty() ) {
        // No consecutive matrices found
        visitAllNodes(matmulInstruction, visited);
        return transformSingleOrderedMatmul(instruction, visited, mpcValue);
    }

    auto *mpcType       = mpcValue->getType();
    auto *argsType      = getTupleType(matmulArgs, M);
    auto *reorderMethod = getOrRealizeSequreOptimizationHelper(M, "matmul_reordering", {mpcType, argsType}, {});
    assert(reorderMethod);

    auto *reorderCall = util::call(reorderMethod, {mpcValue, util::makeTuple(matmulArgs, M)});
    assert(reorderCall);

    matmulInstruction->replaceAll(reorderCall);
    return true;
}

void transformOrderedMatmul( Value *instruction, Value *mpcValue ) {
    std::set<Value *> visited;
    while ( transformSingleOrderedMatmul(instruction, visited, mpcValue) );
}

void reorderConsecutiveMatmuls( SeriesFlow *series, Value *mpcValue ) {
    for ( auto it = series->begin(); it != series->end(); ++it ) transformOrderedMatmul(*it, mpcValue);
}

} // namespace sequre