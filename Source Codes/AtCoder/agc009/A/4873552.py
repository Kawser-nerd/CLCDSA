N = int(input())
A = []
B = []
for i in range(N):
    Ai,Bi = map(int,input().split())
    A.append(Ai)
    B.append(Bi)
ans = 0
for i in reversed(range(N)):
    if (A[i]+ans) % B[i] == 0:
        continue
    ans += B[i]-((A[i]+ans) % B[i])
print(ans)