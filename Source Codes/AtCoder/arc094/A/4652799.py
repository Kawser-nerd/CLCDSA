A, B, C = map(int, input().split())

A, B, C = sorted([A, B, C])

x = C - B
y = C - A
def func(x, y):
  return ((y-x)//2 + x)

if ((x-y) % 2) == 1:
  print(1 + func(x, y+1))
else:
  print(func(x, y))