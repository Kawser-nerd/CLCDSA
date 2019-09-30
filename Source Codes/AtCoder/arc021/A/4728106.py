import sys
input = sys.stdin.readline
n = 4
a = [tuple(map(int,input().split())) for i in range(4)]
judge = True

for i in range(n):
    for j in range(n):
        if i+1 <= n-1:
            if a[i][j] == a[i+1][j]:
                judge = False
        if j+1 <= n-1:
            if a[i][j] == a[i][j+1]:
                judge = False
if judge:
    print('GAMEOVER')
else:
    print('CONTINUE')