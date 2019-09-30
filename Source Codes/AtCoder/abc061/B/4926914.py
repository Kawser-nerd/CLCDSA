I=lambda:map(int,input().split())
N,M=I()
r=range(N)
m={i:0 for i in r}
for _ in[0]*M:
  a,b=I()
  m[a-1]+=1
  m[b-1]+=1
for i in r:print(m[i])