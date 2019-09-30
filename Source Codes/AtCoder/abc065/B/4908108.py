n = int(input())

a = {i + 1:int(input()) for i in range(n)}

x = 1

for i in range(n):
  x = a[x]
  if x == 2:
    print(i + 1)
    break
else:
  print(-1)