N = int(input())
S1 = input()
S2 = input()
MOD = 10**9+7
s = []
if N > 1 and S1[0] == S1[1]:
    ans = 6
    i = 2
    before = 0
else:
    ans = 3
    i = 1
    before = 1
while(i<N):
    if i < N-1 and S1[i] == S1[i+1]:
        ans *= 2 if before else 3
        i += 2
        before = 0
    else:
        ans *= 2 if before else 1
        i += 1
        before = 1
        
    ans %= MOD
print(ans)