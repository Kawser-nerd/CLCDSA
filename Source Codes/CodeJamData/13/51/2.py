# f = open('/home/jongman/Downloads/A-small-attempt0.in'); rl = f.readline
rl = raw_input
cases = int(rl())

def get_expected(placed, lowest, override):
    partial = [p for p in placed if p <= lowest]
    if override > 0:
        partial = partial[:-override]

    only_mine = 37 - len(placed)

    lowest_cnt = only_mine + len(partial) 
    if lowest_cnt == 0: return 0
    ret = 0.0
    ret += lowest * 36.0 * only_mine / float(lowest_cnt)
    for p in partial:
        ret += 36.0 * (lowest - p) * 1.0 / lowest_cnt
    return ret


for cc in xrange(cases):
    budget, bets = map(int, rl().split())
    placed = sorted(map(int, rl().split()))
    
    ret = 0.0
    queue = [1] + placed + [p-1 for p in placed] + [p+1 for p in placed]
    queue = sorted(set(queue))
    seen = set(queue)
    while queue:
        lowest = queue.pop()
        if lowest == 0: continue
        needed_budget = (37 - len(placed)) * lowest
        for p in placed: needed_budget += max(0, lowest - p)
        
        if budget < needed_budget: continue
        remaining_budget = budget - needed_budget

        partial = len([p for p in placed if p <= lowest])

        lowest_cnt = 37 - len(placed) + partial
        if lowest_cnt == 0: continue
        larger = [p for p in placed if p > lowest]
        if larger:
            next_larger = min(larger)
            can_replicate = min(next_larger - lowest - 1,
                                remaining_budget / lowest_cnt)
        else:
            can_replicate = remaining_budget / lowest_cnt
        if can_replicate > 0:
            if (lowest + can_replicate) not in seen:
                seen.add(lowest + can_replicate)
                queue.append(lowest + can_replicate)
            if (lowest + can_replicate - 1) not in seen:
                seen.add(lowest + can_replicate - 1)
                queue.append(lowest + can_replicate - 1)

        for exclude in xrange(0, min(remaining_budget, partial)+1):
            # import pdb; pdb.set_trace()
            cand = get_expected(placed, lowest, exclude) - exclude - needed_budget
            # print ('lowest = %d required_budget = %d exclude = %d ret = %.4lf' %
            #        (lowest, needed_budget, exclude, cand))
            ret = max(ret, cand)

    print 'Case #%d: %.10lf' % (cc + 1, ret)
        
