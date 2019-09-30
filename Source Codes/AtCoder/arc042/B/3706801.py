from math import sqrt
X, Y = map(int, input().split())
N = int(input())
P = []
for i in range(N):
  P.append(list(map(int, input().split())))
  
P.append(P[0])
'''
ax+by+c=0, (p,q)
dist = abs(ap+bq+c) / sqrt(a**2 + b**2)
'''
def calc(p1, p2):
  x1,x2,y1,y2 = p1[0]-X, p2[0]-X, p1[1]-Y, p2[1]-Y
  area = abs(x1*y2 - y1*x2)
  return area / sqrt((x1-x2)**2 + (y1-y2)**2)

ans = 1e9
for i in range(N):
  ans = min(ans, calc(P[i],P[i+1]))
  
print(ans)