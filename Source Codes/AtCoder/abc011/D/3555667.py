N,D = map(int,input().split())
X,Y = map(int,input().split())
X = abs(X)
Y = abs(Y)

if X%D != 0 or Y%D != 0 or (N*D+X-Y)%(2*D) != 0 or X+Y > N*D:
    print(0)
    exit()

def fourcomb(n,k):
    res = 1
    for i in range(k):
        res *= (n-i)/(k-i)
        res /= 4
    return res

ans = 0
for x in range(X//D,(N*D+X-Y)//(2*D)+1):
    y = x-X//D
    z = (N*D+X+Y)//(2*D)-x
    w = z-Y//D
    ans += fourcomb(N,x)*fourcomb(N-x,y)*fourcomb(N-x-y,z)*0.25**w

print(ans)