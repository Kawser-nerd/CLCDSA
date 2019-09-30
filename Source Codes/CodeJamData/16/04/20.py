#p4

def num_to_posn(num, K, C):
    ans = []
    for _ in xrange(C):
        ans.append(num%K)
        num /= K
    return ans #lowest term first

def posn_to_num(A, K):
    num = 0
    for ix,v in enumerate(A):
        num += (K**ix)*v
    return num

def solve(K,C,S):
    #Each step, we can see at most C
    if S*C < K: return "IMPOSSIBLE"
    to_see = set(range(K))
    ans = []
    while to_see:
        ct = 0
        buf = []
        while to_see and ct <C:
            ct += 1
            buf.append(to_see.pop())
        while len(buf) < C:
            buf.append(0)
        num = posn_to_num(buf, K) + 1
        ans.append(num)
    return " ".join(map(str,ans))

########
fo = open('out.txt','w')
with open('in.txt','r') as fi:
    rr = lambda: fi.readline().strip()
    rrI = lambda: int(rr())
    rrM = lambda: map(int,rr().split())
    for tc in xrange(rrI()):
        K,C,S = rrM()
        zetaans = solve(K,C,S)
        zeta = "Case #%i: "%(tc+1) + str(zetaans)
        print zeta
        fo.write(zeta+'\n')
fo.close()
