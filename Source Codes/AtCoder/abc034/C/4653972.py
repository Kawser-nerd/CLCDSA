a,b = map(int,input().split())
MOD = 10**9+7
a -= 1
b -= 1
def f(n):
  ret = 1
  for i in range(1,n+1):
    ret *= i
    ret %= MOD
  return ret

print((f(a+b)*pow(f(a),MOD-2,MOD)*pow(f(b),MOD-2,MOD))%MOD)