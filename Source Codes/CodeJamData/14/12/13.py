import sys

def prework(argv):
    '''do something according to argv,
    return a message describing what have been done.'''
    
    return "nothing"

def once():
    '''to cope once'''
    n = int(input())
    g = [list() for _ in range(n)]
    for i in range(n-1) :
        x, y = [int(x) for x in input().split()]
        x -= 1; y -= 1;
        g[x].append(y)
        g[y].append(x)
    def calc(l, i) :
        if i == n :
            return (len(l) if check(l) else 0), l
        l.append(i)
        return max(calc(l[:], i+1), calc(l[:-1], i+1))
    def getc(l) :
        return sorted([len([_ for _ in g[x] if _ in l]) for x in l])
    def check(l) :
        c = getc(l)
        if len(c) == 0 or len(c) == 1 :
            return True
        def expand(visited, n) :
            if len(n) == 0 :
                return visited
            nn = []
            for x in n :
                for i in g[x] :
                    if i in l and i not in visited :
                        nn.append(i)
                        visited.append(i)
            return expand(visited, nn)
        if len(expand([], [l[0]])) != len(l) :
            return False
        if c[-1] > 3 or c[0] < 1:
            return False
        if len([_ for _ in c if _ == 2]) != 1 :
            return False
        return True
    ans, l = calc([], 0)
    printerr(getc(l))
    printerr(l)
    return n-ans

def printerr(*v):
    print(*v, file=sys.stderr)

def main():
    TT = int(input())
    for tt in range(1,TT+1):
        printerr("coping Case %d.."%(tt))
        ans = once()
        print("Case #%d: %s"%(tt, (ans)))

if __name__ == '__main__' :
    msg = prework(sys.argv)
    print("prework down with", msg, file=sys.stderr)
    main()
