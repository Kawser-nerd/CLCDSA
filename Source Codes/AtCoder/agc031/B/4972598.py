N=int(input())
MOD=10**9+7
memo={}

#prev_num?????????????
prev_num=1
prev=None

for _ in range(N):
  c=int(input())
  if c==prev:
    continue
  tmp=prev_num
  if c in memo:
    tmp+=memo[c]
  tmp%=MOD
  #memo[c]????????????????????
  #??c???????????????????????
  memo[c]=tmp
  prev_num=tmp
  prev=c
print(prev_num)