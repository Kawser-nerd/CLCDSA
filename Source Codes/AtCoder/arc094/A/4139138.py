a,b,c=map(int,input().split())
a,b,c=sorted([a,b,c])

#parity=set(list(map(lambda x: x % 2,[a,b,c])))
parity=list(map(lambda x: x % 2,[a,b,c]))

if len(set(parity))==1:
    print(int((3*max(a,b,c)-a-b-c)/2))
else:
    if (b-a)%2==0:
        ex=1
    else:
        ex=2
    print(int((max(a,b,c)-a)/2)+int((max(a,b,c)-b)/2)+int((max(a,b,c)-c)/2) + ex)