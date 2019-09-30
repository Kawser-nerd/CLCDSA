A,B,C = map(int,input().split())
if A==B==C:
  if A%2:
    print(0)
  else:
    print(-1)
else:
  ans = 0
  while True:
    if A%2 or B%2 or C%2:
      break
    else:
      A,B,C = (B+C)//2,(A+C)//2,(A+B)//2
      ans += 1
  print(ans)