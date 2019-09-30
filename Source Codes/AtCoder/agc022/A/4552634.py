S = input()

if S == 'zyxwvutsrqponmlkjihgfedcba':
    print(-1)
    exit()

tmp = {a: 0 for a in 'abcdefghijklmnopqrstuvwxyz'}

for x in S:
    tmp[x] += 1

tmp2 = []
if all(x == 1 for x in tmp.values()):
    for i in range(len(S)-1, 0, -1):
        tmp2.append(S[i])
        if S[i-1] < S[i]:
            tmp2 = [x for x in tmp2 if x > S[i-1]]
            print(S[:i-1]+min(tmp2))
            exit()
else:
    for k, v in tmp.items():
        if v == 0:
            tmp2.append(k)
    print(S+min(tmp2))