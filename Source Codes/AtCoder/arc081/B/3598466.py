N = int(input())
S1 = input()
S2 = input()
ans = 0
i = 0
if S1[0] == S2[0]:
    ans = 3
    i = 1
else:
    ans = 6
    i = 2
while(i < len(S1)):
    if S1[i] == S2[i]:
        if S1[i - 1] == S2[i - 1]:
            ans *= 2
            ans %= (10 ** 9 + 7)
        i += 1
    else:
        if S1[i - 1] != S2[i - 1]:
            ans *= 3
            ans %= (10 ** 9 + 7)
        else:
            ans *= 2
            ans %= (10 ** 9 + 7)
        i += 2
print(ans)