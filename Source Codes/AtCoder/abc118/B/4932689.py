N, M = map(int, input().split())
K = [0] * N
A = [list(map(int, input().split())) for i in range(N)]
count = 0
for i in range(1, M+1, 1): 
    likecount = 0
    for j in range(N): 
        for k in range(1, A[j][0]+1, 1): 
            if A[j][k] == i:
                likecount += 1
    if likecount == N: 
        count += 1
print(count)