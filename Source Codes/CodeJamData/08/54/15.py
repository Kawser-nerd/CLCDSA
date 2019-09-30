rocks = {}
num_ways = {}
mod = 10007
def num_u_ways(r, c, H, W):
    if(r >= H or c >= W):
        return 0
    if((r,c) in rocks):
        return 0
    if(r == H - 1 and c == W - 1):
        return 1
    if((r,c) in num_ways):
        return num_ways[(r,c)]
    a = num_u_ways(r+2, c+1, H, W)
    b = num_u_ways(r+1, c+2, H, W)
    num_ways[(r,c)] = (a + b) % mod
    return num_ways[(r,c)]


filename = "D-small-attempt0.in"
f = open(filename, 'r')
of = open("D-small.out", 'w')

N = int(f.readline())

for x in xrange(N):
    l = f.readline().split(' ')
    H = int(l[0])
    W = int(l[1])
    R = int(l[2])
    rocks = {}
    for y in xrange(R):
        l = f.readline().split(' ')
        rocks[(int(l[0]) - 1, int(l[1]) - 1)] = True
    num_ways = {}
    ans = num_u_ways(0, 0, H, W)
    print >> of, "Case #%d: %d" % (x + 1, ans)



