N = int(input())
A = list(map(int,input().split(' ')))
GCD = A[0]

def alg_gcd(a,b):
  if a % b == 0:
    return b
  else:
    return alg_gcd(b,a%b)

for i in range(1,N):
  GCD = alg_gcd(GCD,A[i])
print(GCD)