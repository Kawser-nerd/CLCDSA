num = int(input())
S = list(input())


ans = 0
total = 0
for n in S:
  if n == "I":
    total += 1
  elif n == "D":
    total -= 1
  if total > ans:
    ans = total

print(ans)