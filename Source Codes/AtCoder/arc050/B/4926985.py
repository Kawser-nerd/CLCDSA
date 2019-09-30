r,b = map(int,input().split())
x,y = map(int,input().split())

ok = 0
ng = 10**18
while abs(ok-ng) > 1:
    mid = (ok+ng)//2
    if min(r,b) < mid:
        ng = mid
    else:
        pr = r-mid
        pb = b-mid
        if mid > pr//(x-1)+pb//(y-1):
            ng = mid
        else:
            ok = mid
print(ok)