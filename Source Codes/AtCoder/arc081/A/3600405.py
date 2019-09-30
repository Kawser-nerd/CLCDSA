lfl={}
l1=0
l2=0
n=int(input().strip())
a=list(map(int, input().split()))

for i in range(n):
    if a[i] in lfl:
        lfl[a[i]]+=1
    else:
        lfl[a[i]]=1
    if lfl[a[i]]>=2:
        if l1<a[i]:
            l2=l1
            l1=a[i]
            lfl[a[i]]-=2
        elif l2<a[i]:
            l2=a[i]
            lfl[a[i]]-=2
print(l1*l2)