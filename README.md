# Shechi

Shechi is an end-to-end, statically compiled and performance-engineered Pythonic framework for building efficient multiparty homomorphic encryption (MHE) pipelines.

## Via podman/docker

**Note:** Input data is generated at random because the original input data is proprietary.

Run all Shechi benchmarks via [podman or docker](https://hub.docker.com/r/anonconfsubm/shechi):
```bash
mkdir results && sudo podman run --mount type=bind,source=$(pwd)/results,destination=/sequre/results --security-opt label=disable -e "CODON_DEBUG=lt" -e --privileged --rm -t anonconfsubm/shechi:anon scripts/run.sh -release benchmarks --local --jit --stdlib-builtin --king --pca --gwas-without-norm
```

Or run the container in interactive mode to explore Shechi:
```bash
mkdir results && sudo podman run --mount type=bind,source=$(pwd)/results,destination=/sequre/results --security-opt label=disable -e "CODON_DEBUG=lt" -e --privileged --rm -it anonconfsubm/shechi:latest /bin/bash
```
