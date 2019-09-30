a=list(map(int,input().split()))
k,h=a[1],a[1]
k+=a[0]-a[0]%2
k+=a[3]-a[3]%2
k+=a[4]-a[4]%2
if min(a[0],a[3],a[4])>0:
    h+=3
    a[0],a[3],a[4]=a[0]-1,a[3]-1,a[4]-1
    h+=a[0]-a[0]%2
    h+=a[3]-a[3]%2
    h+=a[4]-a[4]%2
print(max(k,h))