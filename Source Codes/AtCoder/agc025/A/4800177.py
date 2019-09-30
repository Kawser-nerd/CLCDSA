n = int(input())
ans = pow(10, 15)
for a in range(1, n):
  b = n - a
  adg, bdg = 0, 0
  while a != 0:
    adg += a % 10
    a //= 10
  while b != 0:
    bdg += b % 10
    b //= 10
  if ans > adg + bdg:
    ans = adg + bdg
print(ans)