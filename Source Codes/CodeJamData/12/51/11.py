def getinput():
    N = input()
    L = map(int,raw_input().split())
    P = map(int,raw_input().split())
    return N,L,P

def go(inp):
    N,L,P = inp
    ans = zip(L,P,range(N))
    for i in range(N):
        cs = 0
        cp = 1
        for j in range(1,N-i):
            if ans[j][1]*ans[j-1][0]>ans[j-1][1]*ans[j][0]:
                ans[j-1],ans[j] = ans[j],ans[j-1]
    return " ".join(str(j) for _,_2,j in ans)

def main():
    T = input()
    inps = [getinput() for t in range(T)]
    from multiprocessing import Pool
    p = Pool(4)
    res = p.map(go,inps)
    for t,v in enumerate(res):
        print "Case #%d: %s" % (t+1,v)

if __name__=='__main__':
    main()
