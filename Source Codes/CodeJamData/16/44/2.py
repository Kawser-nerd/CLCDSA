import itertools


def check(d, order, so_far=[]):
    n = len(d)
#    print(len(order))
#    print(so_far)
    if len(order) == 0:
        return True
#    print("WAT")
    if all(d[order[0]][j] == "0" or j in so_far for j in range(n)):
        return False
    for j in range(n):
        if d[order[0]][j] == "1" and j not in so_far:
            if not check(d, order[1:], so_far + [j]):
                return False
    return True

def check_root(d):
    n = len(d)
    for order in itertools.permutations(range(n)):
        if not check(d, order):
            return False
    return True


def run():
    n = int(input())
    d = []
    for _ in range(n):
        d.append(list(input().strip()))

    zeroes = []
    for i in range(n):
        for j in range(n):
            if d[i][j] == "0":
                zeroes.append((i, j))

    for i in range(0, len(zeroes)+1):
        for fills in itertools.combinations(zeroes, i):
            d2 = list(list("1" if (i,j) in fills else d[i][j] for j in range(n)) for i in range(n))
#            print(d2)
            if check_root(d2):
                return i


tc = int(input())
for i in range(tc):
    res = run()
    print("Case #%d: %d" % (i+1, res))
