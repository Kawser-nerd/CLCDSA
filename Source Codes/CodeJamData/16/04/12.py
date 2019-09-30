import sys
import math

def prework(argv):
    '''do something according to argv,
    return a message describing what have been done.'''
    
    return "nothing"

def base_conv(i_list, from_base) :
    s = 0
    for i in reversed(i_list) :
        s *= from_base
        s += i
    return s

def once():
    '''to cope once'''
    [k, c, s]  = [int(x) for x in input().split()]
    
    if s < math.ceil(k/c) : 
        return "IMPOSSIBLE"
    
    ans_list = list()
    for ic in range(0,k,c) :
        l = list()        
        for j in range(c) :
            if ic+j >= k :
                break
            l.append(ic+j)
        printerr(l)
        ans_list.append(base_conv(l, k))
    return " ".join(str(x+1) for x in ans_list)
    
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
