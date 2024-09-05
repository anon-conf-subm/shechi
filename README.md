# Shechi

Shechi is an end-to-end, statically compiled and performance-engineered Pythonic framework for building efficient multiparty homomorphic encryption (MHE) pipelines.

## Via podman/docker

**Note:** Input data is generated at random because the original input data is proprietary.

Run all Shechi benchmarks via [podman or docker](https://hub.docker.com/r/anonconfsubm/shechi):
```bash
sudo podman run --mount type=bind,source=$(pwd)/results,destination=/sequre/results --security-opt label=disable -e "CODON_DEBUG=lt" -e --privileged --rm -t anonconfsubm/shechi:anon scripts/run.sh -release benchmarks --local --jit --stdlib-builtin --king --pca --gwas-without-norm
```

## Installation

**Note:** Shechi runs only on Linux at the moment.

Git-clone Shechi:
```bash
git clone https://github.com/anon-conf-subm/shechi.git && cd shechi
```

Install [Codon](https://github.com/exaloop/codon):
```bash
mkdir $HOME/.codon && curl -L https://github.com/anon-conf-subm/shechi/releases/download/Anon/codon-linux-x86_64.tar.gz | tar zxvf - -C $HOME/.codon --strip-components=1
```

Assuming Codon is installed in `$HOME/.codon` install Shechi:
```bash
curl -L https://github.com/anon-conf-subm/shechi/releases/download/Anon/shechi-linux-x86_64.tar.gz | tar zxvf - -C $HOME/.codon/lib/codon/plugins
```

## Benchmarks

**Note:** Input data is generated at random because the original input data is proprietary.

Run all benchmarks:
```bash
CODON_DEBUG=lt scripts/run.sh -release benchmarks --local --jit --stdlib-builtin --king --pca --gwas-without-norm
```
