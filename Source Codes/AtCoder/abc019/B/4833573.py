S = input()

s = 0
e = 1
split_S = []

for i in range(1, len(S)):
    if S[i-1] == S[i]:
        e += 1
    else:
        split_S.append(S[s:e])
        s = e
        e = e+1
split_S.append(S[s:e])

ans = ''
for s in split_S:
    ans += s[0] + str(len(s))

print(ans)