input()
a = list(map(int, input().split()))

dp = 1
for x in a:
  dp |= dp << x

s = sum(a)
dp >>= (s + 1) // 2
dp <<= (s + 1) // 2
dp = bin(dp)

print(len(dp) - len(dp.rstrip('0')))