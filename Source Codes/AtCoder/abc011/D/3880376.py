import sys
sys.setrecursionlimit(10000000)
N,D=map(int, input().split())
X,Y=map(int, input().split())
X=abs(X)
Y=abs(Y)
def kj(a):
    if a==0:
        return 1
    else:
        return a*kj(a-1)
if X%D!=0 or Y%D!=0:
    print(0)
else:
    X//=D
    Y//=D
    D=1
    if N-X-Y<0 or (N-X-Y)%2!=0:
        print(0)
    else:
        sum=kj(N)
        bunbo=4**N
        bunsi=0
        tmp=kj(N)
        for i in range((N-X-Y)//2+1):
            bunsi+=tmp//(kj(X+(N-X-Y)//2-i)*kj((N-X-Y)//2-i)*kj(Y+i)*kj(i))
        print(bunsi/bunbo)