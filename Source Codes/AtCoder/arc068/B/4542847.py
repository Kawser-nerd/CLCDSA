from collections import defaultdict
N=int(input())
A=[int(i) for i in input().split()]
dd=defaultdict(int)
for a in A:
    dd[a]+=1
num=0
s=0
for p,n in dd.items():
    num+=1
    if n%2==0:
        s+=1
        s%=2
print(num-s)
#print(num,s,dd)