n = int(input())
alist = [int(input()) for _ in range(n)]

np = 0
remain = 0
for a in alist:
  if a == 0:
    remain = 0
  elif remain == 0:
    np += a // 2
    remain = a % 2
  else:
    np += (a + remain) // 2
    remain = (a + remain) % 2
print(np)