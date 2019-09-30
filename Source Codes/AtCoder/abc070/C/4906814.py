N = int(input())
def gcd(a,b):
  while(b>0):
    a,b = b,a%b
  return a

def lcm(a,b):
  G = gcd(a,b)
  L = (a*b)//G #ab = GL
  return L

for i in range(N): 
  t = int(input())
  if(i == 0): ans = t
  else: ans= lcm(ans,t)
print(ans)