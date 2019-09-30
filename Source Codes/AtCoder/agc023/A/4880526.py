N = int(input())
A = list(map(int,input().split()))
S = [0]
for i in range(N):
    S.append(S[i]+A[i])
S.sort()
now = S[0]
s = 1
ans = 0
for i in range(1,N+1):
    if now == S[i]:
        s += 1
    else:
        ans += s*(s-1)//2
        s = 1
    now = S[i]
ans += s*(s-1)//2
print(ans)