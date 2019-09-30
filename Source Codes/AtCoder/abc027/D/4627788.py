#!/usr/bin/env python3
S = list(input())
li = []
c = 0
for i in range(len(S))[::-1]:
    if S[i] == 'M':
        li.append(c)
    else:
        c += 1 if S[i] == '+' else -1

li.sort()
m = len(li) // 2
print(-sum(li[:m]) + sum(li[m:]))