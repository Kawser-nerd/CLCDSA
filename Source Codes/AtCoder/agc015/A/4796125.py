N, A, B = map(int, input().split())
if N >= 2 and A <= B:
  print((N-2)*B - (N-2)*A + 1)
elif N >= 2:
  print(0)
elif A == B:
  print(1)
else:
  print(0)