# python template for atcoder1
import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline

mat = [[0]*4 for _ in range(4)]
for i in range(4):
    l = list(map(int, input().split()))
    for j in range(4):
        mat[i][j] = l[j]

f = False
for i in range(4):
    for j in range(3):
        if mat[i][j] == mat[i][j+1]:
            f = True
            break

if not f:
    for i in range(4):
        for j in range(3):
            if mat[j][i] == mat[j+1][i]:
                f = True
                break
if f:
    print("CONTINUE")
else:
    print("GAMEOVER")