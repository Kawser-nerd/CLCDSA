# coding: utf-8
# Your code here!
n,a,b,c,d=map(int,input().split())
for i in range(n):
    x,y=(a+c*i,a+d*i)
    j=n-i-1
    z,w=(b+c*j,b+d*j)
    if x<=z<=y or x<=w<=y:
        print('YES')
        break
else:
    print('NO')