import sys

cache = {}
def positions(w, let):
    if (w, let) in cache:
        return cache[(w, let)]
    p = []
    for i, l in enumerate(w):
        if l == let:
            p.append(i)
    cache[(w, let)] = tuple(p)
    return cache[(w, let)]
        
def max_cost(d, letters):
    solutions = []
    new_d  = []
    for i, word in enumerate(d):
        new_d.append((-i,word))
    lengths = {}
    for w in new_d:
        l = len(w[1])
        if l not in lengths:
            lengths[l] = []
        lengths[l].append(w)
        
    for d in lengths.values():
        solutions.append(_max_cost(d, letters))
    return max(solutions)

def _max_cost(d, letters):
    if len(d) == 1:
        return 0, d[0]

    dont_have = []
    have = {}
    l = letters[0]
    letters = letters[1:]
    for pos, word in d:
        if l not in word:
            dont_have.append((pos,word))
            continue
        p = positions(word, l)
        if p not in have:
            have[p] = []
        have[p].append((pos,word))
    c = 0
    if len(have) != 0:
        c += 1

    if dont_have:
        a1 = _max_cost(dont_have, letters)
        a1 = a1[0]+c, a1[1]
        
    a2 = None
    for possible in have.values():
        tmp = _max_cost(possible, letters)
        if a2 is None or tmp > a2:
            a2 = tmp
    if dont_have and a2:
        sol = max(a1, a2)
    elif dont_have:
        sol = a1
    else:
        sol = a2
    return sol

if __name__ == "__main__":
    T = int(raw_input())
    for i in range(1, T+1):
        sys.stderr.write('%d\n' % i)
        c_cache = {}
        N, M = map(int, raw_input().strip().split())
        d = []
        for j in range(N):
            d.append(raw_input().strip())
        letters = []
        for j in range(M):
            letters.append(raw_input().strip())
        solutions = []
        for let in letters:
            solutions.append(max_cost(d, let)[1][1])
        print "Case #%d:" % i,
        for s in solutions:
            print s,
        print

        
