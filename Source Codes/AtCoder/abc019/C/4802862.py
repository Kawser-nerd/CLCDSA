from collections import defaultdict as f
s=f(int)
n=int(input())
a=list(map(int,input().split()))
for i in a:
    while i%2==0:
        i//=2
    s[i]+=1
print(len(list(s)))