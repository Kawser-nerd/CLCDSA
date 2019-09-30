def triplets(p):
    for a in range(p, 10+1):
        for b in range(max(a-2, 0), min(a, 10) + 1):
            for c in range(max(a-2, b-2, 0), min(a, b, 10) + 1):
                yield (a, b, c)
def surprising(triplet):
    return abs(min(triplet) - max(triplet)) == 2

def solve(S, p, points):
    if not points:
        if S == 0:
            return [0]
    else:
        ts = [t for t in triplets(p) if sum(t) == points[0] and not(surprising(t) and S == 0)]
        sol = [(t, solve(S - int(surprising(t)), p, points[1:])) for t in ts]
        sol = [(t, s[0]) for (t, s) in sol if s]
        if sol:
            return [max(s for (t, s) in sol) + 1]
        ts = [t for t in triplets(0) if sum(t) == points[0] and not(surprising(t) and S == 0)]
        sol = [(t, solve(S - int(surprising(t)), p, points[1:])) for t in ts]
        sol = [(t, s[0]) for (t, s) in sol if s]
        if sol:
            return [max(s for (t, s) in sol)]
        # if forp:
        #     ts = [t for t in triplets(p) if sum(t) == points[0] and not(surprising(t) and S == 0)]
        #     sol = [(t, solve(S - int(surprising(t)), p, points[1:], True)) for t in ts]
        #     sol = [(t, s[0]) for (t, s) in sol if s]
        #     if sol:
        #         return [max(s for (t, s) in sol) + 1]
        #     # ts = [t for t in triplets(p) if sum(t) == points[0] and not(surprising(t) and S == 0)]
        #     sol = [(t, solve(S - int(surprising(t)), p, points[1:], False)) for t in ts]
        #     sol = [(t, s[0]) for (t, s) in sol if s]
        #     if sol:
        #         return [max(s for (t, s) in sol) + 1]
        # ts = [t for t in triplets(p) if sum(t) == points[0] and not(surprising(t) and S == 0)]
        # sol = [(t, solve(S - int(surprising(t)), p, points[1:], False)) for t in ts]
        # sol = [(t, s[0]) for (t, s) in sol if s]
        # if sol:
        #     return [max(s for (t, s) in sol) + 1]

data = open('B-small-attempt0.in', 'r')
T = int(data.readline().strip())
for case in range(1, T+1):
    line = list(map(int, data.readline().split()))
    # N = line[0]
    S = line[1]
    p = line[2]
    points = sorted(line[3:], reverse=True)
    print 'Case #{}: {}'.format(case, solve(S, p, points)[0])
    
