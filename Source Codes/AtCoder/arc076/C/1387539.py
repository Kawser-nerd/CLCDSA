R,C,N = map(int,input().split())

edges = []

def convert(x,y):
  if y == 0:
    return x
  if x == R:
    return R+y
  if y == C:
    return R+C+R-x
  if x == 0:
    return R+C+R+C-y
  else:
    return -1


for i in range(N):
  a,b,c,d = map(int, input().split())
  
  p,q = convert(a,b),convert(c,d)
  if p >= 0 and q >= 0:
    edges.append((p,q) if p < q else (q,p))

edges.sort()

# print(edges)


stack = [R+R+C+C]
flag = 'YES'
for a,b in edges:
  while a >= stack[-1]:
    stack.pop()

  if b > stack[-1]:
    flag = 'NO'
    break
  else:
    stack.append(b)

print(flag)