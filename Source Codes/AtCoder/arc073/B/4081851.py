def solve():
  I=lambda:map(int,input().split())
  N,W=I()
  g={}
  for _ in[0]*N:
    a,b=I()
    g[a]=g.get(a,[])+[b]
  *w,=g.keys()
  v=[]
  for i in range(len(w)):
    s=[0]+sorted(g[w[i]])[::-1]
    for i in range(1,len(s)):
      s[i]+=s[i-1]
    v.append(s)
  for _ in[0]*(4-len(w)):
    w.append(10**18)
    v.append([0])
  ans=0
  for i in range(len(v[0])):
    s0=w[0]*i
    for j in range(len(v[1])):
      s1=s0+w[1]*j
      if s1>W:break
      for k in range(len(v[2])):
        s2=s1+w[2]*k
        if s2>W:break
        l=min((W-s2)//w[3],len(v[3])-1)
        ans=max(ans,v[0][i]+v[1][j]+v[2][k]+v[3][l])
  print(ans)
if __name__=='__main__':
  solve()