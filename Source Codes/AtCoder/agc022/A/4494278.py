S = input()
import sys

if S == 'zyxwvutsrqponmlkjihgfedcba':
    print(-1)
    sys.exit(0)

atoz = list(map(chr,range(97,123)))
charmap = dict()
for c in atoz:
    charmap[c] = 0

for s in S:
    charmap[s] += 1

flag = 0
for c in atoz:
    if charmap[c] == 0:
        flag = 1
        S = S + c
        break

if flag == 0:
    index = 0
    for i in range(len(S)-1):
        if S[-1-i] > S[-2-i]:
            index = -2-i
            break
    tmp = sorted(list(S[index+1:]))
    for t in tmp:
        if t > S[index]:
            S = S[:index]+t
            break

print(S)