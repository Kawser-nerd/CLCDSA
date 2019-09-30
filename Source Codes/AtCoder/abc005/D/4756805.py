# python template for atcoder1
import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline

N = int(input())
grid = []
for _ in range(N):
    grid.append(list(map(int, input().split())))
S = [[0]*(N+1) for _ in range(N+1)]

Q = int(input())
query = [int(input()) for _ in range(Q)]


def solve():
    for i in range(N):
        for j in range(N):
            S[i+1][j+1] = S[i][j+1]+S[i+1][j]-S[i][j]+grid[i][j]
    val = [0]*(N*N+1)
    for x1 in range(N):
        for x2 in range(x1+1, N+1):
            for y1 in range(N):
                for y2 in range(y1+1, N+1):
                    area = (x2-x1)*(y2-y1)
                    s = S[x2][y2]-S[x1][y2]-S[x2][y1]+S[x1][y1]
                    val[area] = max(val[area], s)
    for i in range(N**2):
        val[i+1] = max(val[i], val[i+1])
    for q in query:
        print(val[q])


solve()