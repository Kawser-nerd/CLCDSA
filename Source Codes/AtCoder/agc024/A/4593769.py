A,B,C,K = map(int, input().split() )

if K % 2 == 0:
  ans = (A-B)
else:
  A,B,C = B+C, A+C, A+B
  ans =  (A-B)

if abs(ans) > 10**18:
  print("Unfair")
else:
  print(ans)