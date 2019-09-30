N,M = map(int,input().split())
X = list(map(int,input().split()))
if N >= M:
    print(0)
    exit()
X.sort()
d = [X[i+1]-X[i] for i in range(M-1)]
d.sort()
ans = sum(d[:M-N])
print(ans)