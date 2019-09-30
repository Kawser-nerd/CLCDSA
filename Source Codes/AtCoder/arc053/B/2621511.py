S=list(input())
d={}
for i in S:
    if i in d:
        d[i]+=1
    else:
        d[i]=1

l=[]
o=0
e=0
for i in d:
    l.append(d[i])
    o+=d[i]%2
    e+=d[i]//2
l.sort()

if o==0:
    print(e*2)
else:
    print((e//o)*2+1)