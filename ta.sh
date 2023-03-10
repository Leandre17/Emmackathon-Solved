#!/usr/bin/env bash

set -x

EXEC=$1
STUDENT_OUTPUT="./student_output"

EXEC=$1
MY_OUTPUT="./my_output"

ls
ls "$3/Ex0$2/"
ls "Ex0$2/"
ls solution

./$3/Ex0$2/$1 > $STUDENT_OUTPUT
./solution/Ex0$2/$1 > $MY_OUTPUT

diff $STUDENT_OUTPUT $MY_OUTPUT
