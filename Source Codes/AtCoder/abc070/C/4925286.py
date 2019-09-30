n=int(input())
t=1
import fractions
for i in range(n):
  j=int(input())
  t=t*j//fractions.gcd(t,j)
print(t)