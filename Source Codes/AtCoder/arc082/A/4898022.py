import collections
N=int(input())
A=list(map(int,input().split(' ')))
counter=collections.Counter(A)
Y=sorted(list(counter.keys()))
ans=-1
if max(Y)-min(Y)<=2:
  ans=N
else:
  Y_all = [ counter[i] for i in range(min(Y),max(Y)+1) ]
  for i in range(len(Y_all)-2):
    ans = max(sum(Y_all[i:i+3]), ans)
print(ans)