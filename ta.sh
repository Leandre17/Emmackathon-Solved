#!/usr/bin/env bash

EXEC=$1
STUDENT_OUTPUT="./student_output"

EXEC=$1
MY_OUTPUT="./my_output"


./$1 > $STUDENT_OUTPUT
../$1 > $MY_OUTPUT

diff $STUDENT_OUTPUT $MY_OUTPUT
