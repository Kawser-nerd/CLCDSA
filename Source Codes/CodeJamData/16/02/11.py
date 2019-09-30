import sys

def prework(argv):
    '''do something according to argv,
    return a message describing what have been done.'''
    
    return "nothing"

def once():
    '''to cope once'''
    s = input()
    s += "+"
    s = list(reversed(s))
    
    return len(list(1 for a,b in zip(s, s[1:]) if a != b))
    
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
