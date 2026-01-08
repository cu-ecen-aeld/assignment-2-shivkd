#!/bin/sh

writefile="$1"
writestr="$2"
if [ "$#" -ne 2 ]; then
    echo "ERROR: Needs 2 ARGS"
    exit 1
fi
dirpath=$(dirname "$writefile")

if ! mkdir -p "$dirpath"; then
    echo "COULD NOT MAKE directory path"
    exit 1
fi

if ! printf "%s\n" "$writestr" > "$writefile"; then 
    echo "Error in writing to file"
    exit 1
fi
exit 0
