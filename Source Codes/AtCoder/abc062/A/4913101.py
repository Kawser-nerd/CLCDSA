N = set(map(int, input().split()))
A = {1, 3, 5, 7, 8, 10, 12}
B = {4, 6, 9, 11}
C = {2}
if (N <= A or N <= B or N <= C):
  print('Yes')
else:
  print('No')