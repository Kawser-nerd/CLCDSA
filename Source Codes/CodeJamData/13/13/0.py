import sys
R, N, M, K = 8000, 12, 8, 12

bino = [[0] * 30 for i in xrange(30)]
for i in xrange(30):
    bino[i][i] = bino[i][0] = 1
    for j in xrange(1, i):
        bino[i][j] = bino[i-1][j-1] + bino[i-1][j]

import cPickle as pickle
from os import path

if not path.exists('cache.pickle'):
    cards = []
    cnt = []

    def generate(cur, num, ways):
        if len(cur) == N:
            cards.append(cur)
            cnt.append(ways)
        elif num <= M:
            for use in xrange(0, N - len(cur) + 1):
                generate(cur + [num] * use, num + 1, ways * bino[N - len(cur)][use])

    generate([], 2, 1)
    C = len(cnt)
    print 'generated ', C

    from collections import defaultdict

    possible = []
    inverted_index = defaultdict(set)
    for i in xrange(C):
        if i % 10 == 0:
            print i, '..'
        prods = {}
        for subset in xrange(2**N):
            prod = 1
            for j in xrange(N):
                if (subset & (2**j)):
                    prod *= cards[i][j]
            prods[prod] = prods.get(prod, 0) + 1
            inverted_index[prod].add(i)
        possible.append(prods)
    
    pickle.dump((cards, cnt, possible, inverted_index),
                open('cache.pickle', 'wb'))
else:

    sys.stderr.write('loading...\n')
    cards, cnt, possible, inverted_index = pickle.load(open('cache.pickle', 'rb'))
    sys.stderr.write('loaded.\n')

rl = raw_input
t = int(rl())
R, N, M, K = map(int, rl().split())
assert (R,N,M,K) == (8000,12,8,12)
print 'Case #1:'

for i in xrange(R):
    nums = map(int, rl().split())
    candidates = None
    for num in nums:
        cands = inverted_index[num]
        if candidates is None:
            candidates = cands
        else:
            candidates = cands.intersection(candidates)

    chance = {c: 1.0 for c in candidates}
    for num in nums:
        for c in candidates:
            chance[c] *= possible[c][num] / (2.0 ** N)
    max_chance = 0
    ret = [2] * N
    for c, prob in chance.items():
        if max_chance < prob * cnt[c]:
            max_chance = prob * cnt[c]
            ret = cards[c]
    print ''.join(map(str, ret))

            


