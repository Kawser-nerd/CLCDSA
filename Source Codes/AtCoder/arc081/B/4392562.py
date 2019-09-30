N = int(input())
S = input()
T = input()
cnt = 0
ans = 0
tateyoko = ''
if S[0] == T[0]:
  ans += 3
  cnt += 1
  tateyoko = 'tate'
else:
  ans += 6
  cnt += 2
  tateyoko = 'yoko'
while cnt < N:
  if tateyoko == 'tate':
    if S[cnt] != T[cnt]:
      ans *= 2
      cnt += 2
      tateyoko = 'yoko'
    else:
      ans *= 2
      cnt += 1
  else:
    if S[cnt] != T[cnt]:
      ans *= 3
      cnt += 2
    else:
      cnt += 1
      tateyoko = 'tate'
print(ans%1000000007)