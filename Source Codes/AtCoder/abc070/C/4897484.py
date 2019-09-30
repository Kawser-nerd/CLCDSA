n=int(input())
def gcd(a,b):
  while b:a,b=b,a%b
  return a
def lcm(a,b):return a*b//gcd(a,b)
ans=int(input())
for i in range(n-1):
  a=int(input())
  ans=lcm(ans,a)
print(ans)