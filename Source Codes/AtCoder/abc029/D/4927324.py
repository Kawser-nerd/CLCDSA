n = input().strip()
ans = 0
if len(n) == 1:
  print(1)
else:
  for i, (_n, _nn) in enumerate(zip(n, n[1:])):
    if i == 0:
      if _n != '1':
        ans += pow(10, len(n) - 1)
      else:
        ans += int(n[i+1:]) + 1
    elif _n == '1':
      ans += int(n[:i]) * pow(10, len(n) - i - 1) + int(n[i+1:]) + 1
    else:
      if _n == '0':
        ans += pow(10, len(n) - i - 1) * (int(n[:i]))
      else:
        ans += pow(10, len(n) - i - 1) * (int(n[:i]) + 1)
  ans += int(n) // 10 + 1 if n[-1] != '0' else int(n) // 10
  print(ans)