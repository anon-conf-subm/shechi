# Shechi

Shechi is an end-to-end, statically compiled and performance engineered, Pythonic framework for building efficient secure multiparty computation (MPC), homomorphic encryption (HE), and multiparty homomorphic encryption (MHE) pipelines.

## Installation

**Note:** Shechi runs only on Linux at the moment.

Install [Codon](https://github.com/exaloop/codon) first:
```bash
/bin/bash -c "$(curl -fsSL https://exaloop.io/install.sh)"
```

Git-clone Shechi:
```bash
git clone https://github.com/anon-conf-subm/shechi.git && cd shechi
```

Assuming Codon is installed in `$HOME/.codon`, install Shechi from the provided `shechi-linux-x86_64.tar.gz` file:
```bash
tar zxvf shechi-linux-x86_64.tar.gz -C $HOME/.codon/lib/codon/plugins
```

Afterwards, add alias for shechi command:
```bash
alias shechi="find . -name 'sock.*' -exec rm {} \; && $HOME/.codon/bin/codon run -plugin sequre -plugin seq"
```

Finally, you can run Shechi as:
```bash
shechi examples/local_run.codon
```
