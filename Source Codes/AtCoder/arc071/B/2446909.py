import collections

mod = 1000000007

def solve():
    n,m = map(int,input().split())
    x = list(map(int,input().split()))
    y = list(map(int,input().split()))
    X = int()
    for i in range(1,n):
        X += (x[i]-x[i-1])*i*(n-i)
        X %= mod
    Y = int()
    for i in range(1,m):
        Y += (y[i]-y[i-1])*i*(m-i)
        Y %= mod
    print((X*Y)%mod)


if __name__ == "__main__":
    solve()