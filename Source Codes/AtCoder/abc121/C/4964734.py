import sys;n,m=input().split();m=int(m);a=[];i=n=c=0;a=sorted(tuple(map(int,e.split()))for e in sys.stdin)
while m>0:c+=a[i][0]*a[i][1];m-=a[i][1];i+=1
print(c+m*a[~-i][0])