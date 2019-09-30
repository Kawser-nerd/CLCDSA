import sys
N, M = map(int, input().split())
A = [input() for s in range(N)]
B = [input() for s in range(M)]
for i in range(N - M + 1):
    for j in range(N - M + 1):
        flg = 1
        for x in range(M):
            for y in range(M):
                if B[x][y] !=  A[i+x][j+y]:
                    flg = 0
        if flg == 1:
            print('Yes')
            sys.exit()
print('No')