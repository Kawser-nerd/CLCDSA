D, G = map(int, input().split())
p, c = [], []
for i in range(D):
  P, C = map(int, input().split())
  p.append(P)
  c.append(C)
  
def f(a,b):
  if a==0:
    return 10**9
  m = min(b//(a*100),p[a-1])
  s = 100*a*m
  if m == p[a-1]:
    s += c[a-1]
  if s < b:
    m += f(a-1,b-s)
  return min(m,f(a-1,b))

print(f(D,G))