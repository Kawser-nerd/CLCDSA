dir_next = {
    "N": "\\",
    "E": "/",
    "S": "\\",
    "W": "/",
}

dir_effect_of_slash = {
    ("N", "/"): "W",
    ("N", "\\"): "E",
    ("E", "/"): "S",
    ("E", "\\"): "N",
    ("S", "/"): "E",
    ("S", "\\"): "W",
    ("W", "/"): "N",
    ("W", "\\"): "S",
}

dir_step_effect = {
    "N": (-1, 0, "S"),
    "E": (0, +1, "W"),
    "S": (+1, 0, "N"),
    "W": (0, -1, "E"),
}

def traverse(r, c, m, i, j, d):
    if i < 0 or i >= r:
        return
    if j < 0 or j >= c:
        return

    if m[i][j] is None:
        m[i][j] = dir_next[d]

    d = dir_effect_of_slash[(d, m[i][j])]
    eff = dir_step_effect[d]
    i += eff[0]
    j += eff[1]
    d = eff[2]
    traverse(r, c, m, i, j, d)


def pos(r, c, x):
    i, j = 0, 0
    d = None
    if x >= c + r + c:
        i, j = r - 1 - (x - (c + r + c)), 0
        d = "W"
    elif x >= c + r:
        i, j = r - 1, c - 1 - (x - (c + r))
        d = "S"
    elif x >= c:
        i, j = x - c, c - 1
        d = "E"
    else:
        i, j = 0, x
        d = "N"
    return i, j, d


def verify(r, c, m, matches):
    def follow(i, j, d):
        if i < 0:
            return j
        if j >= c:
            return c + i
        if i >= r:
            return c + r + (c-1 - j)
        if j < 0:
            return c + r + c + (r-1 - i)
        d = dir_effect_of_slash[(d, m[i][j])]
        eff = dir_step_effect[d]
        i += eff[0]
        j += eff[1]
        d = eff[2]
        return follow(i, j, d)

    for i in range(2 * (r + c)):
        if follow(*pos(r, c, i)) != matches[i]:
            return False
    return True


def run():
    r, c = tuple(int(x) for x in input().split())
    n = 2 * (r + c)
    order = list(int(x) - 1 for x in input().split())
    matches = n * [None]
    for i in range(n // 2):
        matches[order[2*i]] = order[2*i+1]
        matches[order[2*i+1]] = order[2*i]

    m = list(list(None for _ in range(c)) for _ in range(r))

    stack = []
    for k in range(n):
        if len(stack) > 0 and stack[-1] == matches[k]:
            i, j, d = pos(r, c, stack[-1])
            stack.pop()
            traverse(r, c, m, i, j, d)
        else:
            stack.append(k)

    if len(stack) > 0:
        return "IMPOSSIBLE"

    for i in range(r):
        for j in range(c):
            if m[i][j] is None:
                m[i][j] = "/"

    if not verify(r, c, m, matches):
        return "IMPOSSIBLE"

    s = ""
    for i in range(r):
        for j in range(c):
            s += m[i][j]
        s += "\n"
    return s


tc = int(input())
for i in range(tc):
    res = run()
    print("Case #%d:\n%s" % (i+1, res.strip()))
