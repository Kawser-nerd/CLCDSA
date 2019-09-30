def check(mask):
    for e in mask:
        if e==1: return True
    return False

def main():
    n,m=map(int,input().split(" "))
    ia=[list(map(int,input().split(" "))) for _ in range(n)]
    a=[[0 for _ in range(m)] for _ in range(n)]
    for i in range(n):
        for j in range(m):
            a[i][ia[i][j]-1]=j
    mask=[1 for _ in range(m)]
    res=1000
    while check(mask):
        cnt=[0 for _ in range(m)]
        for alst in a:
            mi=3000
            pos=-1
            for i in range(m):
                if alst[i]<mi and mask[i]==1:
                    pos=i
                    mi=alst[i]
            cnt[pos]+=1
        ma=max(cnt)
        res=min(res,ma)
        for i in range(m):
            if cnt[i]==ma: mask[i]=0

    print(res)            


main()