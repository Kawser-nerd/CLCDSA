A,B=map(int,input().split())
grid=[['#']*50+['.']*50 for i in range(100)]
A-=1
B-=1
for i in range(0,43,2):
    for j in range(0,100,2):
        if A<=0:
            break
        grid[j][i]='.'
        A-=1
for i in range(66,100,2):
    for j in range(0,100,2):
        if B<=0:
            break
        grid[j][i]='#'
        B-=1
print(100,100)
for i in range(100):
    print(''.join(grid[i]))