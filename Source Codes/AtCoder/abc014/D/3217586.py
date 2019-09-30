import sys
input = sys.stdin.readline

N = int(input())
G = [[] for x in range(N + 1)]
for i in range(N - 1):
    x, y = [int(x) for x in input().split()]
    G[x].append(y)
    G[y].append(x)

P = [0 for x in range(N + 1)] #?
d = [0 for x in range(N + 1)] #???????0????
P[1] = 1
import sys
sys.setrecursionlimit(200000)
def makeTree(p, i):
    for g in G[i]:
        if g == p: continue
        P[g] = i
        d[g] = d[i] + 1
        makeTree(i, g)

root = 1
makeTree(0, root)

P_set = []
P_set.append(P)
for i in range(17):
    P_set.append([P_set[-1][p] for p in P_set[-1]])

def calc_ancestor(x, distance):
    i = 0
    while distance != 0:
        if distance & 1:
            x = P_set[i][x]
        distance >>= 1
        i += 1
    return x

def search_common(a, b):
    for i in range(17):
        a_p, b_p = P_set[i][a], P_set[i][b]
        if a_p == b_p:
            if i == 0: return d[a_p]
            return search_common(a, b)
        a, b = a_p, b_p

Q = int(input())
for q in range(Q):
    a, b = [int(x) for x in input().split()]
    long  = b if d[a] < d[b] else a
    short = b if long == a else a
    D = d[long] - d[short]
    long = calc_ancestor(long, D)
    if long == short:
        s = d[long]
    else:
        s = search_common(short, long)
    # print(s)
    print(D + (d[long] - s) * 2 + 1)

    # while long != short:
    #     distance += 2
    #     long = P[long]
    #     short = P[short]
    # print(distance + 1)