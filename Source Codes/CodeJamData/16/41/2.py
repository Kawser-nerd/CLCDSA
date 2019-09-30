
wins_over = {
    "R": "S",
    "S": "P",
    "P": "R"
}

def reorder(foo):
    if len(foo) == 1:
        return foo
    l = reorder(foo[:len(foo)//2])
    r = reorder(foo[len(foo)//2:])
    return "".join(sorted([l, r]))

def reverse(n, start):
    lineup = [start]
    for i in range(n):
        new_lineup = []
        for c in lineup:
            new_lineup.extend([c, wins_over[c]])
        lineup = new_lineup
    return reorder("".join(lineup))

def run():
    n, r, p, s = tuple(int(x) for x in input().split())
    ress = set()
    for c in wins_over:
        foo = reverse(n, c)
        if foo.count("R") == r and foo.count("P") == p and foo.count("S") == s:
            ress.add(foo)
    if len(ress) == 0:
        return "IMPOSSIBLE"
    else:
        return min(ress)


tc = int(input())
for i in range(tc):
    res = run()
    print("Case #%d: %s" % (i+1, res))
