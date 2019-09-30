n,*a=map(int,open(0).read().split())
d=0
l=[]
a=sorted(enumerate(a),key=lambda x:x[1])
b=a[n//2][1]
c=a[n//2-1][1]
for(k,v)in a:
    d+=1
    if d<n//2+1:
        l.append((k,b))
    else:
        l.append((k,c))
#print(l)
for(k,v)in sorted(l,key=lambda x:x[0]):
    print(v)