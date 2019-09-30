#!/usr/bin/env python3
from math import log, log2
P = float(input())
x = max([0, 1.5 * log2(2 / 3 * P * log(2))])
print(x + pow(2, -x / 1.5) * P)