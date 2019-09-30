c = str(input())
#print(c)
n = len(c)

#print(c[z] == '0')
z=0
while z < n:
    if c[z] != '0':
        break
    z=z+1

#print(z,n)

if z == 0:
    z=1
    while z < n:
        if c[z] != '0':
            break;
        z=z+1
    v=int(c[:z])
else:
    v=int('1'+c[:z])

if z == n:
    print(v,1)
    quit()

#print(v)

for zz in range(z+1,n):
    w=int(c[z:zz])
    #print(w)
    if v<w:
        d=w-v
        s=zz
        ok=True
        while s < n:
            w=w+d
            r=str(w)
            m=min(len(r),n-s)
            #print(r[:m],c[s:s+m])
            if r[:m]!=c[s:s+m]:
                ok=False
                break
            s+=m

        if ok:
            print(v,d)
            quit()

w=int(c[z:n])

if len(str(v+1))>=n-z:
    if str(v+1)[:n-z]==c[z:n]:
        print(v,1)
        quit()

while w<=v:
    w*=10

print(v,(w-v))