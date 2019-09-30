def main():
    def solve(mid):
        a=[0]*(n*2)
        for h,s in zip(b[::2],b[1::2]):
            i=(mid-h)//s
            if i<0:
                return 0
            a[min(i,n)]+=1
        for i in range(n+1):
            a[i]+=a[i-1]
            if a[i]>i+1:
                return 0
        return 1
    n,*b=map(int,open(0).read().split())
    ok=10**18
    ng=-1
    while abs(ok-ng)>1:
        mid=(ok+ng)//2
        if solve(mid):
            ok=mid
        else:
            ng=mid
    print(ok)
if __name__=='__main__':
    main()