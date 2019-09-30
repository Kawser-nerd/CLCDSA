N = int(input())
last = [0,0,0]
for i in range(N):
    ti,xi,yi = map(int,input().split())
    a = ti-last[2] - (abs(xi-last[0])+abs(yi-last[1]))
    if a >= 0  and a % 2 == 0:
        flag = True
    else:
        flag = False
        break
    last = [xi,yi,ti]
if flag:
    print('Yes')
else:
    print('No')