a,b,c=map(int,input().split())
print(['No','Yes'][a+b==c or b+c==a or c+a==b])