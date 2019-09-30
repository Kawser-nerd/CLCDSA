#!/usr/bin/env python3
N = int(input())
W = input().split()
dic = {
        'b': 1, 'c': 1, 'd': 2, 'w': 2, 't': 3, 'j': 3, 'f': 4, 'q': 4,
        'l': 5, 'v': 5, 's': 6, 'x': 6, 'p': 7, 'm': 7, 'h': 8, 'k': 8,
        'n': 9, 'g': 9, 'z': 0, 'r': 0
        }
ans = []
for word in W:
    word = word.lower()
    tmp = ''
    for c in word:
        if c not in dic:
            continue
        tmp += str(dic[c])
    ans.append(''.join(tmp.split()))

ok = False
for x in ans:
    if x == '':
        continue
    if ok:
        print(end=' ')
    print(x, end='')
    ok = True
print('')