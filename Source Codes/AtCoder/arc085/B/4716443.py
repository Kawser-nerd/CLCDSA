n, z, w = map(int, input().split())
alist = list(map(int, input().split()))

if n == 1:
  print(abs(alist[0] - w))
else:
  print(max(abs(alist[-1] - w), abs(alist[-1] - alist[-2])))