def solve():
  n,s,t = (int(i) for i in input().split())
  w = int(input())
  if s<= w and w<= t:
   ans = 1
  else:
   ans = 0
  for i in range(n-1):
    a = int(input())
    w += a
    if s<= w and w<= t:
      ans += 1
    else:
      continue
  print(ans)
solve()