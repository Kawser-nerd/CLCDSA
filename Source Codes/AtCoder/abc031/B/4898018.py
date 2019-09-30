l,h,n,*a=map(int,open(0).read().split())
for i in a:print([-(h<i),l-i][l>i])