N=int(input())
scores=[int(input()) for i in range(N)]
t=sorted([10**5 if score%10==0 else score for score in scores])[0]
S=sum(scores)
if S%10!=0:
  print(S)
else:
  print(S-t) if t!=10**5 else print(0)