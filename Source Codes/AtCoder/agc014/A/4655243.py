A,B,C = list(map(int,input().split()))

if A == B and A == C:
  if A%2==0:
    print(-1)
  else:
    print(0)
  exit()
else:
  cnt = 0
  while True:
    if A%2==0 and B%2==0 and C%2==0:
      A,B,C = (B+C)//2,(A+C)//2,(A+B)//2
      cnt += 1
      continue
    else:
      break
      
print(cnt)