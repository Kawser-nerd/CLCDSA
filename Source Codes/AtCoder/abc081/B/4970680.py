N = int(input())
list = input().split()
ans = 0
is_dev = True
while True:
  for i in range(N):
    list[i] = int(list[i])
    if list[i] % 2 == 1:
      is_dev = False
      break
    list[i] = int(list[i]) / 2

  if not is_dev:
    break
  else:
    ans += 1

print(ans)