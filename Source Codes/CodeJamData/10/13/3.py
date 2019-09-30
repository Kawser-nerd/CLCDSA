import sys

def solve(a,b):
    if a == 0 or b == 0:
        return 1
    if a == b:
        return 0
    if a < b:
        return solve(b,a)
    if a >= 2*b:
        return 1
    else:
        return 1-solve(a%b,b)

def num(a,b1,b2):
    low = 0
    high = a-1
    far = 0
    while low <= high:
        mid = (low+high)/2
        if solve(a,mid) == 1:
            low = mid+1
            far = mid
        else:
            high = mid-1
    add = 0
    if b1 <= far:
        add = min(b2,far)-b1 +1
    actual = 0
    for b in range(b1,b2+1):
        if b < a and solve(a,b) == 1:
            actual += 1
    if add != actual:
        print "ERRROR! %d %d %d %d"%(a,add,actual,far)
    return add

T = int(sys.stdin.readline())
for t in range(T):
    s = sys.stdin.readline().split()
    a1 = int(s[0])
    a2 = int(s[1])
    b1 = int(s[2])
    b2 = int(s[3])
    ans = 0
    for a in range(a1,a2+1):
        ans += num(a,b1,b2)
            
    for b in range(b1,b2+1):
        ans += num(b,a1,a2)
    print "Case #%d: %d"%(t+1,ans)