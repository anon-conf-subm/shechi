# Shechi

Shechi is an end-to-end, statically compiled and performance engineered, Pythonic framework for building efficient multiparty homomorphic encryption (MHE) pipelines.

## Installation

**Note:** Shechi runs only on Linux at the moment.

Git-clone Shechi:
```bash
git clone https://github.com/anon-conf-subm/shechi.git && cd shechi
```

Install [Codon](https://github.com/exaloop/codon) from the provided `codon-linux-x86_64.tar.gz` file:
```bash
mkdir $HOME/.codon && tar zxvf codon-linux-x86_64.tar.gz -C $HOME/.codon --strip-components=1
```

Assuming Codon is installed in `$HOME/.codon`, install Shechi from the provided `shechi-linux-x86_64.tar.gz` file:
```bash
tar zxvf shechi-linux-x86_64.tar.gz -C $HOME/.codon/lib/codon/plugins
```

## Benchmarks
Run all benchmarks:
```bash
CODON_DEBUG=lt scripts/run.sh -release benchmarks --local --jit --all
```
