N = int(input())
S1 = input()
S2 = input()
if S1[0] == S2[0]:
    ans = 3
    i = 1
else:
    ans = 6
    i = 2
MOD = 1000000007
while i < N:
    if S1[i - 1] == S2[i - 1]:
        ans = ans * 2 % MOD
        if S1[i] != S2[i]:
            i += 1
    else:
        if S1[i] != S2[i]:
            ans = ans * 3 % MOD
            i += 1
    i += 1
print(ans)