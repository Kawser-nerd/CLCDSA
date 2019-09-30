N,A,B = list(map(int,input().split()))

if (N == 1 and A != B) or A > B:
  print(0)
else:
  ans = 1 + max(0,(N-2))*(B-A)
  print(ans)