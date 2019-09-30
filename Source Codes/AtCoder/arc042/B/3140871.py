from math import sqrt
x,y = map(int,input().split())
n = int(input())
a = [list(map(int,input().split())) for i in range(n)]
a.append(a[0])

m =float('inf')
for i in range(n):
    s = abs((a[i][0]-x)*(a[i+1][1]-y)-(a[i+1][0]-x)*(a[i][1]-y))/2
    l = sqrt((a[i][0] - a[i+1][0]) ** 2 + (a[i][1] - a[i+1][1]) ** 2)
    m = min(m,2*s/l)
    
print(m)