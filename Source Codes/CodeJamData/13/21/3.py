def solve(armin, sizes):
    # print armin, sizes
    cost = 0
    min_cost = len(sizes)
    while sizes:
        while sizes and sizes[0] < armin:
            # eat as many as possible
            armin += sizes[0]
            del sizes[0]
        min_cost = min(min_cost, cost + len(sizes))
        if sizes:
            # stuck. add an mote of size (armin - 1)
            if armin == 1:
                break
            while sizes[0] >= armin:
                armin = 2*armin - 1
                cost += 1
        min_cost = min(min_cost, cost + len(sizes))
    return min_cost

with open('A-large.in', 'r') as file:
    T = int(file.readline())
    for case in range(1, T+1):
        (armin, num) = map(int, file.readline().split())
        sizes = map(int, file.readline().split())
        assert num == len(sizes)

        sizes.sort()
        print 'Case #{}: {}'.format(case, solve(armin, sizes))

        
