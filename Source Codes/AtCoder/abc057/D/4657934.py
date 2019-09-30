from math import factorial as ff
def cc(n,r):
  return ff(n)//ff(n-r)//ff(r)
n,a,b = map(int, input().split())
l = sorted(list(map(int, input().split())), reverse = True)
ans = 0
x = l[:a]
ave = sum(x)/a
m = l.count(x[0-1])
if len(set(x)) == 1:
  for i in range(a,min(b,m)+1):
    ans += cc(m,i)
else:
  p = x.count(x[-1])
  ans = cc(m,p)
print(ave)
print(ans)