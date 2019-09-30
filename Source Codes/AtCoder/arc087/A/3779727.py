from collections import Counter
N=int(input())
A=list(map(int,input().split()))
Ca=dict(Counter(A))
Dk=Ca.keys()
a=0
for i in Dk:
    if i>Ca[i]:
        a+=Ca[i]
    elif i<Ca[i]:
        a+=Ca[i]-i
print(a)