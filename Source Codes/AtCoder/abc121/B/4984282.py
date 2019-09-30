n,m,c=map(int,input().split())
b=map(int,input().split())
b=[int(i) for i in b]
kazu=0
for i in range(0,n):
    goukei = 0
    a=map(int,input().split())
    a=[int(i) for i in a]
    for j in range(0,m):
        goukei+=a[j]*b[j]
    if goukei+c>0:
        kazu += 1
print(kazu)