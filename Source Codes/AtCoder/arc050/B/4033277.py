tmp = input()
r, b = tmp.split()
rf = float(r)
bf = float(b)
r = int(r)
b = int(b)
tmp = input()
x, y = tmp.split()
xf = float(x)
yf = float(y)
x = int(x)
y = int(y)

def verify(p1,q1,x1,y1,r1,b1):
    if(((x1*p1+q1)<=r1) & ((p1+y1*q1)<=b1)):
        return 1
    else:
        return 0

if(r*y<=b):
    print(r)
elif(b*x<=r):
    print(b)
else:
    q = (x*b-r)//(x*y-1)
    p = (y*r-b)//(x*y-1)
    if(verify(int(p)+2,int(q),x,y,r,b) or verify(int(p),int(q)+2,x,y,r,b) or verify(int(p)+1,int(q)+1,x,y,r,b)):
        print(int(p)+int(q)+2)
    elif(verify(int(p)+1,int(q),x,y,r,b) or verify(int(p),int(q)+1,x,y,r,b)):
        print(int(p)+int(q)+1)
    elif(verify(int(p),int(q),x,y,r,b)):
        print(int(p)+int(q))
    elif(verify(int(p)-1,int(q),x,y,r,b) or verify(int(p),int(q)-1,x,y,r,b)):
        print(int(p)+int(q)-1)
    elif(verify(int(p)-2,int(q),x,y,r,b) or verify(int(p),int(q)-2,x,y,r,b) or verify(int(p)-1,int(q)-1,x,y,r,b)):
        print(int(p)+int(q)-2)