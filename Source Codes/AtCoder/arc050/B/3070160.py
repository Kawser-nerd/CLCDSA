R, B = map(int, input().split())
x, y = map(int, input().split())

def searchsub(l, r):
    if r-l <= 1:
        return l
    m = (l+r)//2
    if B<m:
        return searchsub(l, m)
    else:
        t = (B-m)//y
        if R-t>=m*x:
            return searchsub(m, r)
        else:
            return searchsub(l, m)
        
if R>=x:
    d = searchsub(0, R//x+1)
    print(d + (B-d)//y)
else:
    print(min(R, B//y))