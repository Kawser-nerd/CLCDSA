x = int(input())
ans = 0
for i in range(1,10**9):
  ans += i
  if ans >= x:
    print(i)
    exit()