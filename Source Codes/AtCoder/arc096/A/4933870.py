A,B,C,X,Y=map(int,input().split(' '))
ans=-1
for n_ab in range(max(X,Y)+1):
  n_a = max(X-n_ab, 0)
  n_b = max(Y-n_ab, 0)
  p = n_a*A+n_b*B+n_ab*2*C
  ans=p if ans==-1 or p<ans else ans
print(ans)