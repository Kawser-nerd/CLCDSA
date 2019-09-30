N,x = map(int,input().split())
a_ = list(map(int,input().split()))
a_.sort()

if x == sum(a_):
  print(N)
else:
  sum_a = 0
  for i in range(N):
    if x >= sum_a + a_[i]:
      sum_a += a_[i]
    else:
      break
  print(i)