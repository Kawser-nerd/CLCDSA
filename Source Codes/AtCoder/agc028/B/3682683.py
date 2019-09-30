#?????a,b?????a*x+b*y=1?????
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

# a???(mod m)?????(a?m?????????????)
def mod_inv(a,m):
    x = extgcd(a,m)[0]
    return (m+x%m)%m
    
#########################################################

n = int(input())
a = list(map(int,input().split()))
m = 10**9+7

#r[i]:1/k?i??????
r = [0]
w = 0
for i in range(1,n+1):
    w = (w + mod_inv(i,m))%m
    r.append(w)

#fact = n!
fact = 1
for i in range(1,n+1):
    fact = fact*i%m

res = 0
for j in range(1,n+1):
    #p(i,j)??
    sum_p = (r[j]+r[n-j+1]-1) % m
    
    res = (res + a[j-1]*sum_p*fact) % m

print(res % m)