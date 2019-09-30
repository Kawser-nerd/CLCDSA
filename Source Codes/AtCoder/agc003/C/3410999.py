import bisect
n=int(input())
l=[]
e=[]
for i in range(n//2):
    j=int(input())
    e.append(j)
    l.append(j)
    j=int(input())
    l.append(j)
if n%2==1:
    j=int(input())
    e.append(j)
    l.append(j)
l.sort()
e.sort()
res=0
for i in range(0,n,2):
    if e[min(len(e)-1,bisect.bisect_left(e,l[i]))]!=l[i]:
        res+=1
print(res)