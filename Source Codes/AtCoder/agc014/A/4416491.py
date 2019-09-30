a, b, c = map(int, input().split())

if a % 2 == 1 and b % 2 == 1 and c % 2 == 1:
  print(0)
elif a == b and b == c:
  print(-1)
else:
  _a, _b, _c = a, b, c
  ai = 0
  while True:
    if _a % 2 == 0:
      _a //= 2
      ai += 1
    else:
      break
  bi = 0
  while True:
    if _b % 2 == 0:
      _b //= 2
      bi += 1
    else:
      break
  ci = 0
  while True:
    if _c % 2 == 0:
      _c //= 2
      ci += 1
    else:
      break
  min2 = min(ai, bi, ci)
  div2 = pow(2, min2)
  a //= div2
  b //= div2
  c //= div2
  if (a + b) % 2 == 0 and (a + c) % 2 == 0 and (c + b) % 2 == 0:
    min2 += 1
  print(min2)