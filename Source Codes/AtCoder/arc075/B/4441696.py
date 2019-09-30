N,A,B=map(int,input().split())
H=[int(input()) for _ in range(N)]
H=sorted(H,reverse=True)

ok=max(H)//B+1
ng=0
mid=(ok+ng)//2
while ok-ng>1:
  cntlive=0
  for h in H:
    h-=B*mid
    if h>0:
      cntlive+=(h+A-B-1)//(A-B)
  if cntlive<=mid:
    ok=mid
  else:
    ng=mid
  mid=(ok+ng)//2
print(ok)