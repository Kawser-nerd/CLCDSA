N = int(input())
ans = ''

while N:
  if N % 2:
    N -= 1
    ans += '1'
  else:
    ans += '0'
  N //= -2
if len(ans):
  print(ans[::-1])
else:
  print(0)