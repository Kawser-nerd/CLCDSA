# ??
N=int(input())

sl=[]
pl=[]

# ?1??
s,p=map(str,input().split())
p=int(p)
sl.append(s)
pl.append(p)

# ??????????????????????
mx=p

for i in range(N-1):
  s,p=map(str,input().split())
  p=int(p)
  sl.append(s)
  pl.append(p)

  # ??????
  mx=max(mx,p)

# ??????????????????????????
if mx>sum(pl)/2:
  print(sl[pl.index(mx)])
# ????????'atcoder'???
else:
  print('atcoder')