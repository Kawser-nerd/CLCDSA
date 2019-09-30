q,h,s,d = map(int,input().split())
r = [q,h,s,d]
n = int(input())*4
l = [q,h/2,s/4,d/8]
v = [1,2,4,8]
cost = 0
while n:
  now = l.index(min(l))
  cost += n//v[now] * r[now]
  n %= v[now]
  v.pop(now)
  r.pop(now)
  l.pop(now)
print(cost)