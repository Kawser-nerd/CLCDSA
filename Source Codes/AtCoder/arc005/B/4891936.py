x,y,w = input().split()
x,y = int(x)+7,int(y)+7
A = [input() for i in range(9)]
B = [a[1:][::-1] + a + a[:-1][::-1] for a in A]
C = B[1:][::-1] + B + B[:-1][::-1]

D = {'R':(1,0),'L':(-1,0),'U':(0,-1),'D':(0,1),'RU':(1,-1),'RD':(1,1),'LU':(-1,-1),'LD':(-1,1)}
ans = C[y][x]
for i in range(3):
    dx,dy = D[w]
    x += dx
    y += dy
    ans += C[y][x]
print(ans)