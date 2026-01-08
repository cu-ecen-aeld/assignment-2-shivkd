#!/bin/sh

# Check that exactly two arguments are provided
if [ "$#" -ne 2 ]; then
    echo "Error: Two arguments required."
    echo "Usage: $0 <filesdir> <searchstr>"
    exit 1
fi

filesdir="$1"
searchstr="$2"

# Check that filesdir is a directory
if [ ! -d "$filesdir" ]; then
    echo "Error: Directory '$filesdir' does not exist or is not a directory."
    exit 1
fi

# Count the number of files (regular files) under filesdir
num_files=$(find "$filesdir" -type f | wc -l)

# Count the number of lines matching searchstr in those files
# -R: recursive; 2>/dev/null suppresses permission errors if any
num_matching_lines=$(grep -R "$searchstr" "$filesdir" 2>/dev/null | wc -l)

echo "The number of files are $num_files and the number of matching lines are $num_matching_lines"
