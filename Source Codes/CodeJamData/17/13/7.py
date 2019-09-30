# attack: h_k -= a_d
# buff: a_d += b
# cure: h_d = h_d0
# debuff: a_k = max(a_k - d, 0)

# then after each turn, knight attacks: h_d -= a_k

# possible to defeat knight? if so, what's min number of turns?
# input limits (10^9) suggest that iterative solution / dynamic programming
# won't work; shortest path would be nice but 

# if h_d <= a_k and h_k > a_d then you must cure (or debuff) that turn
# indefinite extension of fight does not count as winning!

# state can be represented as quad (h_d, a_d, h_k, a_k)

# consider optimal sequence supposing knight isn't attacking you (i.e. has power 0), so, just buff and attack
# clearly optimal to buff all up front
# if you buff k times then a_d = a_d0 + b * k and it takes ceil(h_k / a_d) swings to kill the knight; optimal value of k + h_k / (a_d0 + b * k) is where d/dk is 0, or close anyway, so 1 - b * h_k / (a_d0 + b * k) = 0
# b * h_k = a_d0 + b * k
# b * h_k - a_d0 = b * k
# h_k - a_d0 / b = k

# can probably find by iterating?

# ok, so given optimal solution without getting hit, can we extend it to
# optimal solution while getting hit
# seems kind of like rasterization of diagonal line?

# ok let's just write dijkstra search and look at optimal solutions for some big numbers

import collections

State = collections.namedtuple('State', ['hd', 'ad', 'hk', 'ak'])

def solve(hd0, ad0, hk0, ak0, b, d):
    root = State(hd0, ad0, hk0, ak0)
    win = root._replace(ad=0)
    def lose(st):
        return st.hd <= 0
    def win(st):
        return st.hk <= 0

    def hit(st):
        return st._replace(hd=st.hd - st.ak)
    def neighbors(st):
        # attack
        yield (hit(st._replace(hk=st.hk - st.ad)), 'a')
        # buff
        yield (hit(st._replace(ad=st.ad + b)), 'b')
        # cure
        yield (hit(st._replace(hd=hd)), 'c')
        # debuff
        yield (hit(st._replace(ak=max(st.ak - d, 0))), 'd')

    pred = {}
    q = collections.deque()
    q.append(root)
    while q:
        st = q.popleft()
        if win(st):
            break
        if lose(st):
            continue
        for (st2, how) in neighbors(st):
            if st2 in pred:
                continue
            pred[st2] = (st, how)
            q.append(st2)
    else:
        return 'IMPOSSIBLE'
    chain = []
    while st in pred:
        st, how = pred[st]
        chain.append(how)
    chain.reverse()
    return str(len(chain))

if __name__ == '__main__':
    import sys
    fp = open(sys.argv[1])
    def readline():
        return fp.readline().strip()
    num_cases = int(readline())
    for i in xrange(num_cases):
        hd, ad, hk, ak, b, d = [int(x) for x in readline().split()]
        print "Case #%d: %s" % (i + 1, solve(hd, ad, hk, ak, b, d))
