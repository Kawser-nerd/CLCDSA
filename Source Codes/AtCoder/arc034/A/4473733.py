def ans():
  N = int(input())
  max_ = 0
  for _ in range(N):
    a, b, c, d, e = map(int,input().split())
    score = a + b + c + d + e*(110/900)
    if(score > max_):
      max_ = score
  if(max_ == int(max_)):
    print(int(max_))
  else:
    print(max_)
ans()