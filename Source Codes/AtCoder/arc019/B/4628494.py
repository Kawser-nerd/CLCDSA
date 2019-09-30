s = input()
n = len(s)
t = s[::-1]
cnt = 0
for i in range(n):
  if s[i] != t[i]:
    cnt += 1
if n == 1:
  print(0)
elif cnt == 2:
  print(24*2+25*(n-2))
elif cnt == 0 and n%2:
  print(25*(n-1))
else:
  print(25*n)