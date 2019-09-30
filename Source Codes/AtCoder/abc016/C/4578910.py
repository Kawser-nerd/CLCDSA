N, M = map(int, input().split())
mat = [[0] * N for i in range(N)]

for i in range(M):
    a, b = map(int, input().split())
    mat[a-1][b-1]=1
    mat[b-1][a-1]=1
    
import numpy as np

for i in range(N):
    if 1 in mat[i]:
        mat_array = np.array(mat[i])
        mat_temp = [j for j, x in enumerate(mat[i]) if x == 1]
        
        B = 0
        for k in mat_temp:
            B += np.array(mat[k])
            
        if B[i]!=0:
            B[i] = 0
        for l in mat_temp:
            if B[l]!=0:
                B[l]=0
            
        print(np.count_nonzero(B))
        
    else:
        print(0)