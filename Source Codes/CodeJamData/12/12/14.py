# @gilesgardam

def ints():
    return map(int, raw_input().split())

num_cases, = ints()
infty = 9001

for case_num in xrange(1, num_cases + 1):
    n = int(raw_input())
    pairs = []
    for i in xrange(n):
        a, b = ints()
        pairs.append([b, a])
    pairs.sort(reverse=True)
    level = 0
    games = 0
    while pairs:
        if pairs[-1][0] <= level:
            pair = pairs.pop()
            games += 1
            if pair[1] == infty:
                # already played one
                level += 1
            else:
                level += 2
        else:
            finished = True
            for pair in pairs:
                if pair[1] <= level:
                    pair[1] = infty
                    games += 1
                    level += 1
                    finished = False
                    break
            if finished:
                break
    print "Case #%d: %s" % (case_num, str(games) if level == 2 * n else "Too Bad")
