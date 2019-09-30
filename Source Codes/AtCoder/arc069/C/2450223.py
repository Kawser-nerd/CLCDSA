from collections import Counter
N = int(input())
S = list(map(int,input().split()))
T = []
for i in range(N):
    T.append((i,S[i]))
U = sorted(T,key=lambda x:x[1], reverse=True)

Ans = [0]*N
c,v = 0,10**10

for i in range(N-1):
    c+=1
    v = min(v,U[i][0])
    if U[i][1]==U[i+1][1]:
        continue
    else:
        Ans[v] += (U[i][1] - U[i+1][1])*c
else:
    Ans[0] = 0
    Ans[0] = sum(S) - sum(Ans)

for i in range(N):
    print(Ans[i])