def solve():
  mod = 10**9+7
  query = 'abcdefghijklmnopqrstuvwxyz'
  n = int(input())
  s = input()
  ans = 1
  for i in range(26):
    if s.count(query[i])>= 1:
     ans *= 1+s.count(query[i])
     ans %= mod
  print((ans-1)%mod)
solve()