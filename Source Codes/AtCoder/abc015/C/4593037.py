N, K = map(int, input().split())
T = [list(map(int, input().split())) for _ in range(N)]

tmp = T[0]

i = 0
while i != N - 1:
    nex = []
    for j in range(len(tmp)):
        for k in range(K):
            nex.append(tmp[j] ^ T[i+1][k])         
    tmp = nex
    i += 1
   
if 0 in tmp:
    print('Found')
else:
    print('Nothing')