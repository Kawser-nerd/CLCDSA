N,M=map(int,input().split())
if N>=M:
    print(0)
    exit()
X=[int(i) for i in input().split()]
X.sort()
Y=[X[i+1]-X[i] for i in range(M-1)]
Y.sort()
ans=0
for i in range(M-N):
    ans+=Y[i]
print(ans)