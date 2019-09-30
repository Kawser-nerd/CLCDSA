x,y,r=map(int,input().split())
x1,y1,x2,y2=map(int,input().split())

def f(i):
    p,q,n,m=i
    return ((p-n)**2+(q-m)**2)**0.5<r

e=[f([x,y]+i)for i in [[x1,y1],[x1,y2],[x2,y1],[x2,y2]]] #?????????????

f=[x1<=s<=x2 and y1<=t<=y2 for(s,t)in [[x+r,y+r],[x-r,y+r],[x+r,y-r],[x-r,y-r]]] #?????????????
#print(e,f)
if any(e)==0 and any(f)==0:
    print("YES")
    print("YES")
elif all(e) and any(f)==0:
    print("YES")
    print("NO")
elif any(e)==0 and all(f):
    print("NO")
    print("YES")
else:
    print("YES")
    print("YES")