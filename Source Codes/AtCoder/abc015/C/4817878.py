n,k=map(int,input().split())
l=[list(map(int,input().split()))for i in range(n)]
t="Nothing"
for i in range(k**n):
  ans=l[0][i%k]
  if n>1:
    i//=k
    ans=ans^l[1][i%k]
    if n>2:
      i//=k
      ans=ans^l[2][i%k]
      if n>3:
        i//=k
        ans=ans^l[3][i%k]
        if n>4:
          i//=k
          ans=ans^l[4][i%k]
  if ans==0:
    t="Found"
    break
print(t)