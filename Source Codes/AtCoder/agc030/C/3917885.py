K = int(input())
M = 1000

def a(i, j):
    tmp = (i - j) % (M//2) + 1
    if j % 2 == 0 or M + 1 - tmp > K:
        return tmp
    else:
        return M + 1 - tmp
    
if K <= M//2:
    print(K)
    for i in range(K):
        print(*([i+1]*K))
else:
    print(M//2)
    for j in range(M//2):
        print(*([a(i, j) for i in range(M//2)]))