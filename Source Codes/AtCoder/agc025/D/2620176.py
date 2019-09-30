def judge(D):
  n = 0
  while D%4==0:
    n += 1
    D //= 4

  return (lambda x,y: ~((x>>n)^(y>>n))&1) if D%2==1 else (lambda x,y: ~(x>>n)&1)

N,D1,D2 = map(int,input().split())
j1,j2 = judge(D1),judge(D2)
for _,(x,y) in zip(range(N*N),filter(lambda p: j1(*p) and j2(*p), ((x,y) for x in range(N*2) for y in range(N*2)))):
  print(x,y)