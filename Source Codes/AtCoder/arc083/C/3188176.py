from itertools import product

n = int(input())
P = [0, 0] + [int(i) for i in input().split()]
X = [0] + [int(i) for i in input().split()]

C = [[] for i in range (n+1)]

for i, p in enumerate(P):
    C[p].append(i)

def dfs(i):
    if not C[i]:
        return X[i], 0

    A = []
    
    for c in C[i]:
        A.append(dfs(c))

    S = 0
    for a in A:
        S += sum(a)

    dp = [[False]*(X[i]+1) for j in range(len(A)+1)]
    dp[0][0] = True

    for j in range(len(A)):
        for k in range(X[i]+1):
            a, b = A[j]
            if a <= k and dp[j][k-a]:
                dp[j+1][k] = True
            elif b <= k and dp[j][k-b]:
                dp[j+1][k] = True
        if not any(dp[j+1]):
            print('IMPOSSIBLE')
            exit()

    b = 0
    for j in range(X[i], -1, -1):
        if dp[len(A)][j]:
            b = j
            break

    return X[i], S - b

dfs(1)
print('POSSIBLE')