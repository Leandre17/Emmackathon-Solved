#!/usr/bin/env bash

INPUT=$(ls /var/jenkins_home/workspace/status/)
mkdir -p /var/jenkins_home/workspace/status/old/

while IFS='\n' read -ra ADDR; do
	echo -e "\n\n$ADDR :"
    cat /var/jenkins_home/workspace/status/$ADDR
    echo -e "\n\n"
    mv /var/jenkins_home/workspace/status/$ADDR /var/jenkins_home/workspace/status/old/${ADDR}_$BUILD_ID
done <<< "$INPUT"

