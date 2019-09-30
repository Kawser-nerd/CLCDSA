w,h,n= map(int,input().split())
s=[]
for i in range(n):
    s.append(list(map(int,input().split())))
l=0
d=0
for j in range(n):
    if s[j][2]==1 and s[j][0]>l:
        l=s[j][0]
    elif s[j][2]==2 and s[j][0]<w:
        w=s[j][0]
    elif s[j][2]==3 and s[j][1]>d:
        d=s[j][1]
    elif s[j][2]==4 and s[j][1]<h:
        h=s[j][1]

if h-d>0 and w-l>0:
    print((h-d)*(w-l))
else:
    print(0)