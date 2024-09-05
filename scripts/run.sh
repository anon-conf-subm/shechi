#!/usr/bin/env bash

echo "Cleaning up sockets ..."
find . -name 'sock.*' -exec rm {} \;

if [[ $* == *--jit* ]]
then
    echo "Running $2 in $1 mode ..."
    $HOME/.codon/bin/codon run --disable-opt="core-pythonic-list-addition-opt" -plugin sequre -plugin seq $1 scripts/invoke.codon run-$2 ${*:3}
    echo "Cleaning up sockets ..."
    find . -name 'sock.*' -exec rm {} \;
else
    if [[ $* == *--build* ]]
    then
        rm -f ./sequrex
        echo "Compiling $2 in $1 mode ..."
        CC=clang CXX=clang++ $HOME/.codon/bin/codon build --disable-opt="core-pythonic-list-addition-opt" -plugin sequre -plugin seq $1 -o sequrex scripts/invoke.codon
    fi

    if [ ! -f "./sequrex" ]
    then
        echo "Sequre is not built. Make sure to add --build flag in first run." >&2
        return
    fi

    if [[ ! $* == *--build-only* ]]
    then
        echo "Running $2 in $1 mode ..."
        /usr/bin/time -v ./sequrex run-$2 ${*:3}
    fi
fi

echo "Cleaning up sockets ..."
find . -name 'sock.*' -exec rm {} \;
