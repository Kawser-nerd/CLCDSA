R,B=map(int,input().split())
x,y=map(int,input().split())

#t??????
L=0 #True
U=R+1 #False

while U-L>1:
    t=(U+L)//2
    if R-t<0 or B-t<0 or (R-t)//(x-1) + (B-t)//(y-1) < t:
        U=t
    else: L=t
print(L)