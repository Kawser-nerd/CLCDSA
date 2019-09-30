B=[list(map(int,input().split())) for i in range(2)]
C=[list(map(int,input().split())) for i in range(3)]
S=sum(sum(i) for i in B)+sum(sum(i) for i in C)

memo={}

#????
def score(t):
  s=0
  for i in range(2):
    for j in range(3):
      if t[i+1][j]==t[i][j]:
        s+=B[i][j]
  for i in range(3):
    for j in range(2):
      if t[i][j+1]==t[i][j]:
        s+=C[i][j]
  return s

def solve(t,turn=1):
  if str(t) in memo: #??????????????????
    return memo[str(t)]
  if turn == 10:     #??????????????
    # print('t;',t)
    return score(t)
  bs1=0
  bs2=float('inf')
  for i in range(3):
    for j in range(3):
      if not t[i][j] is None:
        continue
      t[i][j]= turn%2 #??????????????
      s=solve(t,turn+1) #????1??????????????
      t[i][j]=None
      bs1=max(bs1,s)
      bs2=min(bs2,s)
  ret=bs1 if turn%2 else bs2 #????????????/???????????????
  memo[str(t)]=ret
  return ret

ret = solve([[None]*3 for i in range(3)])
print(ret)
print(S - ret)