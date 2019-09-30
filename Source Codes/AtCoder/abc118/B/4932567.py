N, M = map(int, input().split())
K = [0] * N
A = [[0 for j in range(M)] for i in range(N)] 
for i in range(N):
    inpt = list(map(int, input().split())) 
    K[i] = inpt[0] 
    for j in range(1, K[i]+1, 1): 
        A[i][j-1] = inpt[j]
count = 0
for j in range(1, M+1, 1): 
    likecount = 0
    for i in range(N): 
        for k in range(K[i]): 
            if A[i][k] == j:
                likecount += 1
    if likecount == N: 
        count += 1
print(count)