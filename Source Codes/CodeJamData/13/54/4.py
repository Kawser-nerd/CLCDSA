
F = None

def f(s,n):
    global F
    if s in F:
        return F[s]
    for i in range(1,n):
        s_ = s[i:] + s[:i]
        if s_ in F:
            return F[s_] 
    
    ans = 0.0

    if len([1 for c in list(s) if c == '.'] ) == 0:
        #print "%s %d %f"%(s,n,ans)
        F[s] = ans
        return ans

    ts = s*2
    dist = 0
    last = 2*n
    for i in reversed(range(2*n)):
        if ts[i] == '.':
            dist = 0
            last = i
        else:
            dist += 1

        if i < n:
            ps = last if last < n else last - n
            ns = s[:ps] + 'X' + s[ps+1:]
            ans += n-(last-i) + f(ns,n)

    ans /= n
    F[s] = ans
    #print "%s %d %f"%(s,n,ans)
    return ans


def main():
    global F

    T = int(raw_input())
    for t in range(1,T+1):
        s = raw_input().strip('\r\n')
        n = len(s)
        F = dict()
        ans = f(s,n)
        print "Case #%d: %.10f"%(t,ans)
    
    
main()