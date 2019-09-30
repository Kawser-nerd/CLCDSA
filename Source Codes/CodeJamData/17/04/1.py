import networkx as nx
from networkx.algorithms import bipartite
from copy import deepcopy

t = int(input())
for tc in range(1, t + 1):
    print("Case #" + str(tc) + ": ", end = "")
    n, z = map(int, input().split())
    l = [["."] * n for _ in range(n)]
    stt = 0
    for _ in range(z):
        a, b, c = input().split()
        l[int(b) - 1][int(c) - 1] = a
        if a == "o": stt += 2
        else: stt += 1
    lcp = deepcopy(l)
    tow = [(i, j) for i in range(n) for j in range(n) if l[i][j] in "ox"]
    bis = [(i, j) for i in range(n) for j in range(n) if l[i][j] in "o+"]
    towx = {i for (i, j) in tow}
    towy = {j for (i, j) in tow}
    ntowx = [i for i in range(n) if i not in towx]
    ntowy = [j for j in range(n) if j not in towy]
    bisx = {i + j for (i, j) in bis}
    bisy = {i - j for (i, j) in bis}
    for k in range(len(ntowx)):
        i, j = ntowx[k], ntowy[k]
        if l[i][j] == "+":
            l[i][j] = "o"
        else:
            assert(l[i][j] == ".")
            l[i][j] = "x"
        stt += 1
    gg = nx.Graph()
    for i in range(2*n - 1):
        gg.add_node((i, 0))
    for i in range(-(n - 1), n):
        gg.add_node((i, 1))
    for (i, j) in bis:
        gg.remove_node((i + j, 0))
        gg.remove_node((i - j, 1))
    for i in range(n):
        for j in range(n):
            if i + j not in bisx and i - j not in bisy:
                gg.add_edge((i + j, 0), (i - j, 1))
    match = bipartite.hopcroft_karp_matching(gg)
    for cc in match:
        if cc[1] == 1: continue
        ppp = cc[0]
        mmm = match[cc][0]
        i = (ppp + mmm) // 2
        j = (ppp - mmm) // 2
        if l[i][j] == "x":
            l[i][j] = "o"
        else:
            assert(l[i][j] == ".")
            l[i][j] = "+"
        stt += 1
    chg = []
    for i in range(n):
        for j in range(n):
            if l[i][j] != lcp[i][j]:
                chg.append((i, j))
    print(stt, len(chg))
    for (i, j) in chg:
        print(l[i][j], i + 1, j + 1)
    
