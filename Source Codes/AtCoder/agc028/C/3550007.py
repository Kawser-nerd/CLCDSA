N = int(input())
A = []
B = []
Sa = 0
Sb = 0
for i in range(N):
    a,b = map(int,input().split())
    A.append([a,i])
    B.append([b,i])
    Sa += a
    Sb += b
C = sorted(A+B)
ind = []
ans = 0
for i in range(N):
    ind.append(C[i][1])
    ans += C[i][0]
ind = set(ind)
if len(ind) == N:
    if C[N-1][1] != C[N][1]:
        ans += C[N][0]-C[N-1][0]
    else:
        ans += min(C[N][0]-C[N-2][0],C[N+1][0]-C[N-1][0])
ans = min(Sa,Sb,ans)
print(ans)