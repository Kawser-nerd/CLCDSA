h,w = map(int,input().split())

import numpy as np
inf = 10**3
C = np.full((10,10),inf,dtype = int)#C[from][to]
for x in range(10):
    for inp,y in zip(input().split(),range(10)):
        C[x][y] = inp
        
A = [list(map(int,input().split())) for _ in range(h)]

def warshallfloyd(lis):
    for k in range(10):
        for i in range(10):
            for j in range(10):
                if i != j and k != i and k != j:
                    C[i][j] = min(C[i][j],C[i][k]+C[k][j])
warshallfloyd(C)
ans = 0
for a in A:
    for aa in a:
        if aa != -1:
            ans += C[aa][1]
print(ans)