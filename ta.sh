#!/usr/bin/env bash

set -x

EXEC=$1
STUDENT_OUTPUT="./student_output"

EXEC=$1
MY_OUTPUT="./my_output"

INPUT=$(ls sujet/Ex0$2/ | grep "input" | cut -c 6-)

chmod +x ./$3/Ex0$2/$1
chmod +x ./solution/Ex0$2/$1


diff $STUDENT_OUTPUT $MY_OUTPUT

TEST_NUMBER=1

while IFS='\n' read -ra ADDR; do
    cat sujet/Ex0$2/input$ADDR | ./$3/Ex0$2/$1 > $STUDENT_OUTPUT
    cat sujet/Ex0$2/input$ADDR | ./solution/Ex0$2/$1 > $MY_OUTPUT
    if [ $(diff $STUDENT_OUTPUT $MY_OUTPUT | wc -l) -ne 0 ]; then 
        echo -e "TEST $TEST_NUMBER FAILLED:"
        diff $STUDENT_OUTPUT $MY_OUTPUT
        exit 84;
    TEST_NUMBER=$((TEST_NUMBER + 1))
done <<< "$INPUT"

