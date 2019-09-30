n = int(input())
p = list(map(int, input().split()))
ans = 0
for i in p:
  ans += max(80-i, 0)
print(ans)