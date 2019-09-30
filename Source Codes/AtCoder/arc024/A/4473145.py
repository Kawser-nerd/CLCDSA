def ans():
  L, R = map(int,input().split())
  l = list(map(int,input().split()))
  r = list(map(int,input().split()))
  cnt = 0
  for ll in l:
    if(ll in r):
      cnt += 1
      r.remove(ll)
  print(cnt)
ans()