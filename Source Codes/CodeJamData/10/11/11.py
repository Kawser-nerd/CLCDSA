from sys import stdin

def main():
    n,k = map(int,stdin.readline().split())
    b = [''.join(stdin.readline().strip().split('.')).rjust(n, '.') for _ in xrange(n)]
    #print b
    def it(s, dir):
        while 0 <= s[0] < n and 0 <= s[1] < n:
            yield b[s[0]][s[1]]
            s = s[0]+dir[0], s[1]+dir[1]
    blue, red = [], []
    def go(it):
        #print list(it)
        bluec = redc = 0
        for i in it:
            if i == 'B':
                bluec += 1
                #print "bluec", bluec
                if bluec >= k:
                    blue.append(True)
            else:
                bluec = 0
            if i == 'R':
                redc += 1
                #print "redc", redc
                if redc >= k:
                    red.append(True)
            else:
                redc = 0
    for i in xrange(n):
        go(it((0,i), (1,0)))
        go(it((i,0), (0,1)))
        go(it((0,i), (1,1)))
        go(it((i,0), (1,1)))
        go(it((0,i), (1,-1)))
        go(it((i,n-1), (1,-1)))
    if red and blue:
        return "Both"
    elif red:
        return "Red"
    elif blue:
        return "Blue"
    else:
        return "Neither"

tno = int(stdin.readline())
for i in xrange(0, tno):
    print "Case #%d: %s"%(i+1, main())
