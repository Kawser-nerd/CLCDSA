A,B,C = map(int, input().split())
if A >= B and A >= C:
  print(A*10+B+C)
elif B >= A and B >= C:
  print(B*10+A+C)
else:
  print(C*10+A+B)