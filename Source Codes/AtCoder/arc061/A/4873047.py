S = input()

ans = 0

if len(S) == 1:
    ans = int(S)
else:
    for i in range(2 ** (len(S) - 1)):
        tmp = S[0]
        for j in range(0, len(S) - 1):
            if i >> j & 1 == 0:
                tmp += S[j + 1]
            else:
                ans += int(tmp)
                tmp = S[j + 1]
        ans += int(tmp)

print(ans)