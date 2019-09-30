import sys

def prework(argv):
    '''do something according to argv,
    return a message describing what have been done.'''
    
    return "nothing"

def once():
    '''to cope once'''
    n, l = [int(x) for x in input().split()]
    def con(raw) :
        return [[int(raw[i][j]) for i in range(len(raw))] for j in range(len(raw[0]))]
    misaki = con(input().split())
    shota = con(input().split())
    
    def calc(g1, g2) :
        c1 = [sum(l) for l in g1]
        c2 = [sum(l) for l in g2]
        def _calc(i) :
            ans = 100000
            def tran(g1) : 
                ans = sorted([[g1[x][y] for x in range(i)] for y in range(n)])
                #print(ans)
                return ans
            if tran(g1) != tran(g2) :
                return ans
            if i == l :
                return 0
            if c1[i] == c2[i] :
                ans = min(ans, _calc(i+1))
            if c1[i] == n-c2[i] :
                g2[i] = [1-x for x in g2[i]]
                ans = min(ans, _calc(i+1)+1)
                g2[i] = [1-x for x in g2[i]]
            return ans
        ans = _calc(0)
        return ans if ans != 100000 else None
    flip = calc(shota, misaki)
    return flip if flip != None else "NOT POSSIBLE"

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
