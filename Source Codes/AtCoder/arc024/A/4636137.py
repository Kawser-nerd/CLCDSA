l,r=map(int,input().split())
ls=list(map(int,input().split()))
rs=list(map(int,input().split()))
c=set(ls)&set(rs)
s=0
print(sum([min(ls.count(e),rs.count(e)) for e in c]))