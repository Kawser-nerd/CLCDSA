D,N = map(int, input().split())
count = 0
x = 0
while count != N:
  x += 1
  if x % 100 ** D == 0 and x % 100 ** (D + 1) != 0:
    count += 1
print(x)