S = input().split("+")

ans=0

for s in S:
  if "0" not in s:
    ans += 1

print(ans)