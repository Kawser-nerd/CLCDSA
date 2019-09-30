import math
n=int(input())
m=n
nn=int(math.sqrt(n)//1)
for i in range(nn//2,nn*3//2+1):
    for j in range(i+1):
        if (abs(i-j)+(n-i*j))<m and i*j<=n:
            m=(abs(i-j)+(n-i*j))
print(m)