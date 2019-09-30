n = int(input())

cop = n
while cop > 10:
  cop //= 10
topdigit = cop

ans = 0
denom = 1

while n // denom > 0:
  if (n // denom) % 10 == 0:
    ans += (n // (10 * denom)) * denom
  elif (n // denom) % 10 == 1:
    ans += (n // (10 * denom)) * denom + n % denom + 1
  else:
    ans += (n // (10 * denom) + 1) * denom
  
  denom *= 10
  
print(ans)