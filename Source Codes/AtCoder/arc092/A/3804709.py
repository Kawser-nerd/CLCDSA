iipt=lambda:int(input())
miipt=lambda:list(map(int,input().split(" ")))
n=iipt()
r=[]
b=[]
for i in range(n):
    r.append(miipt())
for i in range(n):
    b.append(miipt())
r.sort(key=lambda x:x[1], reverse=True)
b.sort()
c=0
for xb, yb in b:
    for i, (xr, yr) in enumerate(r):
        if xr<xb and yr<yb:
            r[i]=(212, 212)
            c+=1
            break
    else:
        continue
print(c)