def gcd(a,b):
  if a>=b:
    if a%b==0:
      return b
    else:
      return gcd(a%b,b)
  else:
    if b%a==0:
      return a
    else:
      return gcd(a,b%a)
  
N=int(input())
HP=[int(i) for i in input().split()]
ans=HP[0]
for i in range(1,N):
  ans=gcd(ans,HP[i])
print(ans)