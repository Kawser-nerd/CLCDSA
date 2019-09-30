import sys
N = int(input())
S = []
for i in range(N):
    a = int(input())
    S.append((a,i))
S.sort()
T = [0]*(N)
for i in range(N):
    T[S[i][1]] = i
if N == 1:
    print(0)
    sys.exit()
ans = 0
for i in range(0,N,2):
    if T[i]%2:
        ans += 1
print(ans)