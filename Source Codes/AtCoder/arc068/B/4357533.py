from collections import Counter

n=int(input())
a=list(map(int,input().split()))

ac=Counter(a)
ans=len(ac)
count=0

for aa in ac.values():
    if aa%2==0:
        count+=1


print(ans-(count%2))