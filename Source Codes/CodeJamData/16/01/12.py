import sys

def prework(argv):
    '''do something according to argv,
    return a message describing what have been done.'''
    
    return "nothing"

def once():
    '''to cope once'''
    n = int(input())
    
    s = set()
    for i in range(1,210) :
        s.update(int(x) for x in str(i*n))
        if all(x in s for x in range(10)) :
            return i*n
    return "INSOMNIA"
    
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
