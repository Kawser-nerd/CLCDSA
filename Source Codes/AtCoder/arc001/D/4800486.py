from copy import deepcopy
def check(x):
    s = []
    d, m = divmod(x, 8)
    for i in range(8):
        s.append(8*i + m)
        s.append(8*d + i)

    for d in [-9, 7]:
        y = deepcopy(x)
        while 0 <= y+d <= 63 and (y%8) > 0:
            y += d
            s.append(y)
    for d in [9, -7]:
        y = deepcopy(x)
        while 0 <= y+d <= 63 and (y%8) < 7:
            y += d
            s.append(y)
    return s


def dfs(se, qu):
    if len(qu) == 8:
        return qu
    #print(len(qu))

    for i in range(64):
        if i in se:
            continue
        ns = set(check(i))
        if len(qu & ns) == 0:
            res = dfs(se|ns, qu|set([i]))
            if not res is None:
                return res

C = []
for _ in range(8):
    C += list(input())

searched = set()
queens = [i for i in range(64) if C[i] == "Q"]

for i in range(3):
    ns = set(check(queens[i]))
    if len(set(queens[:i]) & ns):
        print("No Answer")
        break
    searched = searched | ns
else:
    queens = set(queens)
    qu = dfs(searched, queens)
    if qu is None:
        print("No Answer")
    else:
        ans = ["."]*64
        for q in qu:
            ans[q] = "Q"
        for i in range(8):
            print("".join(ans[i*8:(i+1)*8]))