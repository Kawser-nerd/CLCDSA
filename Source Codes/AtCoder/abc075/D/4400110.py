from bisect import bisect_left
N,K = map(int,input().split())
X = []; Y = []; info = []
for i in range(N):
    x,y = map(int,input().split())
    X.append(x); Y.append(y); info.append([x,y])
X.sort(); Y.sort()

acc = [[0]*(N+1) for i in range(N+1)]
for x, y in info:
    j = bisect_left(X,x)
    i = bisect_left(Y,y)
    acc[i+1][j+1] += 1

for i in range(N+1):
    for j in range(1,N):
        acc[i][j+1] += acc[i][j]

for j in range(N+1):
    for i in range(1,N):
        acc[i+1][j] += acc[i][j]

ans = float('inf')
for t in range(N-1):
    for b in range(t+1,N):
        for l in range(N-1):
            for r in range(l+1,N):
                num = acc[b+1][r+1] - acc[b+1][l] - acc[t][r+1] + acc[t][l]
                if num < K: continue
                S = (Y[b] - Y[t]) * (X[r] - X[l])
                if S < ans:
                    ans = S

print(ans)

def debug():
    for line in acc:
        print(line)