N = int(input())
ans = 0
s = (N//4 +1)
for i in range(s):
  for j in range(s):
    if 4*i+7*j == N:
      ans += 1
print("Yes" if ans != 0 else "No")