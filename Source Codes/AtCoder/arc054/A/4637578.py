l,x,y,s,d=map(int,input().split())
if x>=y:
    ans=((d-s)%l)/(x+y)
else:
    t1=((d-s)%l)/(x+y)
    t2=(l-((d-s)%l))/(y-x)
    ans=min(t1,t2)
print(ans)