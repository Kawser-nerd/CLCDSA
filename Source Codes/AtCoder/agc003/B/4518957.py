n = int(input())
a = [int(input()) for i in range(n)]
ans = 0
tmp = 0
for i in a:
  if i == 0:
    ans += tmp // 2
    tmp = 0
  else:
    tmp += i
ans += tmp // 2
print(ans)