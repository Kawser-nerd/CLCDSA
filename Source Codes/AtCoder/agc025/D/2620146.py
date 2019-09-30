def judge(D):
  n = 0
  while D%4==0:
    n += 1
    D //= 4

  def h1(x,y):
    return ~((x>>n)^(y>>n))&1
  def h2(x,y):
    return ~(x>>n)&1

  return h1 if D%2==1 else h2

N,D1,D2 = map(int,input().split())
j1,j2 = judge(D1),judge(D2)

cnt = 0
for x in range(N*2):
  for y in range(N*2):
    if j1(x,y) and j2(x,y):
      print(x,y)
      cnt += 1
      if cnt >= N*N:
        exit()