n,*a=map(int,open(0));c,s=1,a[0]
while s!=2and c<n:c+=1;s=a[s-1]
print(c*(c<n)or-1)