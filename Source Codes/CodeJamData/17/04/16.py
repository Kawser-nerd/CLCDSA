def dfs(v, vis, back, adj):
    if vis[v]:
        return False
    vis[v] = True

    for to, has in enumerate(adj[v]):
        if has:
            if back[to] == -1 or dfs(back[to], vis, back, adj):
                back[to] = v
                return True

    return False


def match(adj):
    n = len(adj)
    res = []
    back = [-1] * n
    for v in range(n):
        dfs(v, [False] * n, back, adj)

    for i2, b in enumerate(back):
        if b >= 0:
            res.append((b, i2))

    return res

def to_diag(r, c, n):
    return r - c + n - 1, r + c


def from_diag(p1, p2, n):
    return (p1 - n + 1 + p2) // 2, (p2 - p1 + n - 1) // 2


def unused_idxs(used):
    return [i for i in range(len(used)) if not used[i]]


def val(x):
    if x == 3:
        return 2
    elif x == 0:
        return 0
    else:
        return 1


def solve(test):
    n, models = [int(w) for w in input().split()]
    was = [[0] * n for i in range(n)]
    out = [[0] * n for i in range(n)]

    used_rows = [False] * n
    used_cols = [False] * n
    used_diag1 = [False] * (2 * n - 1)
    used_diag2 = [False] * (2 * n - 1)

    for _ in range(models):
        w, r, c = input().split()
        r = int(r) - 1
        c = int(c) - 1
        if w == 'x':
            was[r][c] = out[r][c] = 1
            used_rows[r] = True
            used_cols[c] = True
        elif w == '+':
            was[r][c] = out[r][c] = 2
            p1, p2 = to_diag(r, c, n)
            used_diag1[p1] = True
            used_diag2[p2] = True
        else:
            was[r][c] = out[r][c] = 3
            used_rows[r] = True
            used_cols[c] = True
            p1, p2 = to_diag(r, c, n)
            used_diag1[p1] = True
            used_diag2[p2] = True

    for r, c in zip(unused_idxs(used_rows), unused_idxs(used_cols)):
        out[r][c] += 1

    n_diags = len(used_diag1)
    adj = [[False] * n_diags for i in range(n_diags)]
    for p1 in range(n_diags):
        for p2 in range(n_diags):
            if not used_diag1[p1] and not used_diag2[p2]:
                r, c = from_diag(p1, p2, n)
                if 0 <= r < n and 0 <= c < n and to_diag(r, c, n) == (p1, p2):
                    adj[p1][p2] = True

    pairing = match(adj)
    for p1, p2 in pairing:
        r, c = from_diag(p1, p2, n)
        out[r][c] += 2

    total_value = 0
    for row in out:
        for v in row:
            total_value += val(v)

    changes = [(r, c) for r in range(n) for c in range(n) if out[r][c] != was[r][c]]

    import sys
    print("Case #{}: {} {}".format(test, total_value, len(changes)))
    print("Case #{}: {} {}".format(test, total_value, len(changes)), file=sys.stderr)

    for r, c in changes:
        print("{} {} {}".format(['!', 'x', '+', 'o'][out[r][c]], r + 1, c + 1))


def prepare_input():
    local = False
    task = 'D'
    attempt = -1

    import sys

    if local:
        sys.stdin = open("../input.txt", "r")
    else:
        filename = "../{}-small-attempt{}".format(task, attempt) if attempt >= 0 else "../{}-large".format(task)

        sys.stdin = open(filename + ".in", "r")
        sys.stdout = open(filename + ".out", "w")

        print("filename:", filename[3:], file=sys.stderr)


prepare_input()
tests = int(input())
for test in range(1, tests + 1):
    solve(test)
