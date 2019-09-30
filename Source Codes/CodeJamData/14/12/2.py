#! /usr/bin/env python

import sys
import heapq
fin = open(sys.argv[1], "r")
fout = open("p2.out", "w")

T = int(fin.readline())

def cc(adj, r): #Compute children given adj list and root
    Q = [r]
    ch = [[] for i in range(len(adj))]
    V = [0 for i in range(len(adj))]
    while Q != []:
        cur = Q.pop()
        V[cur] = 1
        for n in adj[cur]:
            if V[n] == 0:
                Q.append(n)
                ch[cur].append(n)
    return ch

def cw(r, chs, w): #compute an array of total descendants including self
    w[r] = 1
    for c in chs[r]:
        w = cw(c, chs, w)
        w[r] += w[c]
    
    return w

def compute_min(r, chs, w): #compute min number of deletions to make tree full
    mins = [compute_min(c, chs, w) for c in chs[r]]
    if len(chs[r]) == 0:
        return 0
    elif len(chs[r]) == 1:
        return w[chs[r][0]]
    elif len(chs[r]) == 2:
        return sum(mins)
        
    ws = [w[c] for c in chs[r]]
    extra = [a - b for a, b in zip(ws, mins)]
    return sum(ws) - sum(heapq.nlargest(2, extra))

for i in range(T):
    print i
    fout.write("Case #" + str(i+1) + ": ")
    N = int(fin.readline())
    if N == 1:
        fout.write("0\n")
        continue
    elif N == 2:
        fin.readline()
        fout.write("1\n")
        continue

    ans = N
    adj = [[] for j in range(N)]
    for j in range(N-1):
        x, y = map(int, fin.readline().split())
        adj[x-1].append(y-1)
        adj[y-1].append(x-1)

    for j in range(N): #try making j the root
        if len(adj[j]) < 2:
            continue

        chs = cc(adj, j)
        weights = cw(j, chs, [0 for k in range(N)])

        cur = compute_min(j, chs, weights)
        ans = min(ans, cur)

    fout.write(str(ans) + "\n")
