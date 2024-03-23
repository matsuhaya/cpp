#! /bin/bash
set -euC

if [[ $# != 1 ]]; then
    exit 1
fi
if [[ -d ./test ]]; then
    rm -r ./test
fi
url="${1}"

oj d "${url}"