N = int(input())
M = 100000
X = [[0] * (M+1) for i in range(4)]
D = []
for _ in range(N):
    d = int(input())
    D.append(d)
    X[0][d] += 1
    
for k in range(4):
    for i in range(1, M+1):
        X[k][i] += X[k][i-1]
    
    if k == 3:
        break
        
    for d in D:
        X[k+1][d] += X[k][d//2]
    
print(X[3][-1]%(10**9+7))