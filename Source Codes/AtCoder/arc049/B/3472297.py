N=int(input())
XYC=[]
for _ in range(N):
    XYC.append(tuple(map(int,input().split())))
    
#t????????
#max(abs(x-x0),abs(y-y0)) <= t/c0 + t/c

L=0 #False
U=10**9 #True

while(U-L>=1e-4):
    
    t=(U+L)/2
    
    mx=[]
    Mx=[]
    my=[]
    My=[]
        
    for x,y,c in XYC:
        
        #?????mx-Mx,my-My
        mx.append(x-t/c)
        Mx.append(x+t/c)
        my.append(y-t/c)
        My.append(y+t/c)
        
    if max(mx)<=min(Mx) and max(my)<=min(My):
        U=t
    else: L=t
    
print(U)