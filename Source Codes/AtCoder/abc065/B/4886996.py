n = int(input())
s = [int(input()) for _ in range(n)]

ai = 0
for i in range(n):
  ai = s[ai] - 1
  if ai == 1:
    print(i + 1)
    exit()
  else:
    continue
print(-1)