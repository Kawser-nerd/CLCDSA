import sys

def num_servings(amount, recipe):
    # maximize n st amount >= recipe * 0.9 * n
    # n <= amount * 10 / (recipe * 9)
    upper_bound = amount * 10 / (recipe * 9)
    # minimize n st amount <= recipe * 1.1 * n
    # n >= amount * 10 / (recipe * 11)
    lower_bound = (amount * 10 + recipe * 11 - 1) / (recipe * 11)
    return lower_bound, upper_bound

assert num_servings(100, 1) == (91, 111), num_servings(100, 1)
assert num_servings(90, 1) == (82, 100), num_servings(90, 1)
assert num_servings(110, 1) == (100, 122), num_servings(110, 1)

if __name__ == "__main__":
    f = sys.stdin
    if len(sys.argv) >= 2:
        fn = sys.argv[1]
        if fn != '-':
            f = open(fn)

    T = int(f.readline())
    for _T in xrange(T):
        N, P = map(int, f.readline().split())
        recipe = map(int, f.readline().split())

        packages = [] # [ingredient][package_idx]
        for i in xrange(N):
            l = []
            for x in map(int, f.readline().split()):
                l.append(num_servings(x, recipe[i]))
            l.sort()
            packages.append(l)

        made = 0
        while all(packages):
            highest_min = -1e9
            for l in packages:
                highest_min = max(highest_min, l[0][0])

            changed = False
            for l in packages:
                if l[0][1] < highest_min:
                    l.pop(0)
                    changed = True
            if changed:
                continue

            # print packages
            for l in packages:
                assert l[0][0] <= highest_min <= l[0][1]
                l.pop(0)
            made += 1

        print "Case #%d: %d" % (_T + 1, made)
