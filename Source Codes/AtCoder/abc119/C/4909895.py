N, A, B, C = [int(i) for i in input().split()]
L = [int(input()) for i in range(N)]
 
def dfs(idx, a, b, c):
 
    if idx == N:
        if a == 0 or b == 0 or c == 0:
            return 1e9
        
        return abs(A - a) + abs(B - b) + abs(C - c)
    
    x = dfs(idx + 1, a, b, c)
    y = dfs(idx + 1, a + L[idx], b, c) + 10*(a != 0)
    z = dfs(idx + 1, a, b + L[idx], c) + 10*(b != 0)
    w = dfs(idx + 1, a, b, c + L[idx]) + 10*(c != 0)
    return min(x, y, z, w);
 
ans = dfs(0, 0, 0, 0);
print(ans)