n = int(input())
s = "........."
cnt = 0
for _ in range(n):
  l = s
  s = input()
  for i in range(9):
    if s[i] == "x" or (s[i] == "o" and l[i] != "o"):
      cnt += 1
print(cnt)