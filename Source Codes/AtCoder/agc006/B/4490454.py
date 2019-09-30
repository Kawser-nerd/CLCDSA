n,x=map(int,input().split())
if n==2and x==2:
    print('Yes',*[1,2,3],sep='\n')
    exit()
a=[[]for _ in range(2*n-1)]
a[n-1]=x
f=[0]*2*n
f[x]=1
try:
    if x>2*n-3:
        a[n-3]=x-2
        a[n-2]=x+1
        a[n]=x-1
        f[x-2]=f[x-1]=f[x+1]=1
    else:
        a[n-3]=x+2
        a[n-2]=x-1
        a[n]=x+1
        f[x-1]=f[x+1]=f[x+2]=1
    if f[0]:
        1/0
except:
    print('No')
    exit()
i=0
for j,v in enumerate(f[1:],1):
    if v:continue
    while a[i]:i+=1
    a[i]=j
print('Yes',*a,sep='\n')