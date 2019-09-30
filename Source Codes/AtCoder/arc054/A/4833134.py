l,x,y,s,d=map(int,input().split())
p=l+s-d
q=d-s
r=l-s+d
if p==0 or q==0 or r==0:
    print(0)
elif q>0 and y>x:
    print(min(q/(x+y),p/(y-x)))
elif q>0:
    print(q/(x+y))
elif q<0 and y>x:
    print(min(abs(q)/(y-x),r/(x+y)))
elif q<0:
    print(r/(x+y))