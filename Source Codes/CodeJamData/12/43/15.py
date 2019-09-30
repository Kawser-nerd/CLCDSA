

def read_input():
    n = int(raw_input())
    x = [int(x) for x in raw_input().strip().split()]
    return n,x

def solve2(l,r,x,p,s):
    if l==r:
        return []
    hl = int(p - (r-l)*s) - 1
    #print "hl =",hl
    heads = []
    for i in range(l,r):
        if x[i]==r:
            heads.append(i)

    result = []
    oh = l-1
    #print heads,hl
    for h in heads:
        ss = float(p - hl)/(r - h)
        #print ss
        #print oh+1,h,hl,ss
        res = solve2(oh+1,h,x,hl,ss)
        result += (res + [hl])
        oh = h

    return result

def solve(l,r,x):
    if l==r:
        return 0

    if x[l]!=r:
        
        r1 = solve(l,x[l],x)
        r2 = solve(x[l]+1,r,x)

        print ">",r1
        print ">",r2
        
        r2h = max(r2)
        if r1[-1] <= r2h:
            hh = r1[-1]
            r1 = [x + r2h - hh + 1 for x in r1]
        return r1 + r2

    else:
        return solve2(l,r,x,0,0) + [0]


def main():
    #print solve(0,5,[1,2,3,4,5])
    #print solve2(0,6,[6,2,3,4,5,6],0,0)

    t = int(raw_input())
    for tt in range(t):
        n,x = read_input()
        result = solve2(0,n,[n] + x,0,0)
        mm = min(result)
        real = []
        for i in result[1:]:
            real.append(i-mm+1)
        real.append(-mm+1)
        if len(real)==n:
            print ("Case #%d: " % (tt+1)) + ' '.join([str(y) for y in real])
        else:
            print ("Case #%d: Impossible" % (tt+1))
            

if __name__=="__main__":
    main()
    
