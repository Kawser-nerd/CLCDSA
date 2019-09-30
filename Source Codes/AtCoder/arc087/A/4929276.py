import collections
N=int(input())
A=list(map(int,input().split(' ')))
counter=collections.Counter(A)
ans=0
for key, val in counter.items():
  ans += val if val < key else val-key
print(ans)