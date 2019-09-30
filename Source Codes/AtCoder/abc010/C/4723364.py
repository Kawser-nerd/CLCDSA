import math
li = list(map(int,input().split()))
x1 = li[0]
y1 = li[1]
x2 = li[2]
y2 = li[3]
t = li[4]
v = li[5]

n=int(input())
x = []
y = []
for i in range(n):
    a,b = map(int,input().split())
    x.append(a)
    y.append(b)

border = t * v

ans = 'NO'
for i in range(n):
    dis1 = math.sqrt((x[i] - x1) ** 2 +(y[i] - y1) **2)
    dis2 = math.sqrt((x[i] - x2) ** 2 +(y[i] - y2) **2)
    if border >= dis1+dis2:
        ans = 'YES'
        break
print(ans)