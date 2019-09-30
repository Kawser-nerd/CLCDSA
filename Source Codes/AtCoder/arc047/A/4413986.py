n, l = map(int, input().split())
s = input()
tab = 1
cnt = 0
for i in range(n):
  if s[i] == "+":
    tab += 1
    if tab > l:
      cnt += 1
      tab = 1
  else:
    tab -= 1
print(cnt)