N,M = map(int,input().split())
S = input()
T = input()
def gcd(a,b):
  if a%b == 0:
    return b
  else:
    return gcd(b,a%b)
p = gcd(M,N)
q = M*N//p
flag = True
for j in range(p):
  if S[N*j//p] != T[M*j//p]:
    flag = False
    break
if flag:
  print(q)
else:
  print(-1)