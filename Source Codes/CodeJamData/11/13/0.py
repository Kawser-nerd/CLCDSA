import sys
rl = lambda: sys.stdin.readline().strip()

def pick(hand, order):
    def cmp(a, b):
        for field in order:
            if a[field] != b[field]:
                return a[field] - b[field]
        return 0

    hand.sort(cmp=cmp)
    #print "order", order
    #for c,s,t in hand: print "card=%d score=%d turn=%d" % (c,s,t)
    ret = hand[-1]
    hand.pop()
    return ret

def play_greedy(hand, turns):
    hand = list(hand)
    ret = 0
    while hand and turns:
        ret += pick(hand, [1])[1]
        turns -= 1
    return ret

t = int(rl())
for cc in range(t):
    n = int(rl())
    hand = [map(int, rl().split()) for i in xrange(n)]
    m = int(rl())
    deck = [map(int, rl().split()) for i in xrange(m)]

    ret = 0
    turns, score = 1, 0
    while turns > 0 and hand:
        ret = max(ret, score + play_greedy(hand, turns))
        if deck:
            use = pick(hand, [2, 0, 1])
        else:
            use = pick(hand, [2, 1])
        #print "play", use
        draw = use[0]
        hand = hand + deck[:draw]
        deck = deck[draw:]
        score += use[1]
        turns += use[2] - 1
    ret = max(ret, score)
    print "Case #%d:" % (cc+1),
    print ret

