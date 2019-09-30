def memoize(func):
    results = {}
    def wrapper(*args):
        if args not in results:
            results[args] = func(*args)
        return results[args]
    return wrapper

def main():
    N = int(raw_input())
    for case in xrange(N):
        P, Q = map(int, raw_input().split())
        releases = tuple(map(int, raw_input().split()))

        @memoize
        def solve(first_cell, last_cell, first_release, last_release):
            min_cost = None
            for release in xrange(first_release, last_release + 1):
                cost = last_cell - first_cell
                if release > first_release:
                    previous_release = release - 1
                    previous_cell = releases[release - 1] - 1
                    cost += solve(first_cell, previous_cell,
                                  first_release, previous_release)
                if release < last_release:
                    next_release = release + 1
                    next_cell = releases[release - 1] + 1
                    cost += solve(next_cell, last_cell,
                                  next_release, last_release)
                if min_cost is None:
                    min_cost = cost
                else:
                    min_cost = min(min_cost, cost)
            return min_cost

        print 'Case #%d: %d' % (case + 1, solve(1, P, 1, Q))

if __name__ == '__main__':
    main()
