#!/usr/bin/env python3

import sys

result = 0.0
for line in sys.stdin:
	result += int(line)
result = result / 2
if result > int(result):
    print(int(result + 1))
else:
    print(int(result))
