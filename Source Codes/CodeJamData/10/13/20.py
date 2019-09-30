filename = "C-small-attempt0.in"
lines = [line.split(" ") for line in open(filename).readlines()[1:]]
lines = [[int(x) for x in line] for line in lines]

def memoize(func):
    memo = {}
    def f(*args):
        if not args in memo:
            memo[args] = func(*args)
        return memo[args]
    return f

@memoize
def win(a,b):
    if a == b:
        return False
    if a < b:
        a, b = b, a
    if a % b == 0:
        return True
    
    if not win(a % b, b):
        return True
    if a%b+b < a and not win(a%b+b,b):
        return True
    return False

#print lines
for idx, line in enumerate(lines):
    a1,a2,b1,b2 = line
    #print a1,a2,b1,b2
    ans = 0
    for x in range(a1,a2+1):
        for y in range(b1,b2+1):
            if win(x,y):
                ans += 1
    print "Case #%d: %d" % (idx+1, ans)
