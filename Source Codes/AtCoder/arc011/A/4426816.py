m,n,new = map(int,input().split())
res,old = 0,0

while new + old >= m:
    res += new
    old += new
    new = 0
    new += (old // m) * n
    old %= m

print(new+res)