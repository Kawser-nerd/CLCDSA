def gcm(a, b) :
  while(b) :
    a, b = b, a%b
  return a
def lcm(a, b) :
  return int(a*b/gcm(a, b))

n, m = map(int, input().split())
s = list(str(input()))
t = list(str(input()))
s_out = []
t_out = []
for i in range(int(gcm(n, m))) :
  s_out.append(s[i*int(n/gcm(n, m))])
for i in range(int(gcm(n, m))) :
  t_out.append(t[i*int(m/gcm(n, m))])
  
if(s_out == t_out) : print(lcm(n, m))
else : print(-1)