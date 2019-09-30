import sys
sys.setrecursionlimit(100000)
def search(x,y):
    if y<0 or y>=10 or x<0 or x>=10:
        return
    if a[x][y]=='x':
        return
    if r[x][y]=='o':
        return

    r[x][y]='o'

    search(x+1,y)
    search(x-1,y)
    search(x,y+1)
    search(x,y-1)

a=[list(input()) for i in range(10)]

for i in range(10):
    for j in range(10):
        if a[i][j]=='x':
            r=[['x']*10 for i in range(10)]
            a[i][j]='o'
            search(i,j)
            if a==r:
                print('YES')
                exit()
            a[i][j]='x'

print('NO')