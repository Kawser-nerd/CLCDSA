L,R = map(int,input().split())
l = list(map(int,input().split()))
r = list(map(int,input().split()))
m = list(set(l))
ans = 0
cl = 0
cr = 0
k = 0
for i in range(len(m)):
  k = m[i]
  cl = l.count(k)
  cr = r.count(k)
  ans += min(cl,cr)
  cl = 0
  cr = 0
print(ans)