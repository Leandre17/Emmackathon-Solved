#!/usr/bin/env bash

set -x

EXEC=$1
STUDENT_OUTPUT="./student_output"

EXEC=$1
MY_OUTPUT="./my_output"

INPUT=$(ls solution/Ex0$2/)

echo "input = $INPUT"

chmod +x ./$3/Ex0$2/$1
chmod +x ./solution/Ex0$2/$1

./$3/Ex0$2/$1 > $STUDENT_OUTPUT
./solution/Ex0$2/$1 > $MY_OUTPUT

diff $STUDENT_OUTPUT $MY_OUTPUT

#while IFS='\n' read -ra ADDR; do
#done <<< "$ALL_CONTAINERS"
