w,h=map(int,input().split())


def extgcd(a,b):
    r = [1,0,a]
    w = [0,1,b]
    while w[2]!=1:
        q = r[2]//w[2]
        r2 = w
        w2 = [r[0]-q*w[0],r[1]-q*w[1],r[2]-q*w[2]]
        r = r2
        w = w2
    #[x,y]
    return [w[0],w[1]]

def mod_inv(a,m):
    x = extgcd(a,m)[0]
    return (m+x%m)%m

m = 10**9+7
res = 1
for i in range(1,w+h-1):
    res = res*i%m
for i in range(1,min(w,h)):
    res = res*mod_inv(i,m)%m
for i in range(1,max(w,h)):
    res = res*mod_inv(i,m)%m
print(res)