#!/usr/bin/env python
S = input()
min = 753
for i in range(len(S)-2):
    if min > abs(int(S[i:i+3]) - 753):
        min = abs(int(S[i:i+3]) - 753)

print(min)