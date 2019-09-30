# -*- coding: utf-8 -*-

S = [i for i in input()]
count = 0

if S.pop(0) == 'A':
    count += 1

if S[1:-1].count('C') == 1:
    count += 1
    S.remove('C')

    if ''.join(S).islower():
        count += 1

print('AC' if count == 3 else 'WA')