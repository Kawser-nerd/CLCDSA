from collections import Counter
n=int(input())
a=tuple([int(i) for i in input().split()])
cnt=dict(Counter(a))
ans=0
for i,j in zip(cnt.keys(),cnt.values()):
    if i>j:
        ans+=j
    elif i!=j:
        ans+=j-i
print(ans)