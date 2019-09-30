
T = int(raw_input())  
for K in xrange (T):
    n, q = [int(g) for g in raw_input().split(" ")]
    e, s = [], []
    for i in xrange(n):
        ei, si = [int(g) for g in raw_input().split(" ")]
        e.append(ei)
        s.append(si)
    dist = []
    for i in xrange(n):
        dist.append([int(g) for g in raw_input().split(" ")])

    nochange = [[-1] * n for i in xrange(n)] 
    for i in xrange(n):
        for j in xrange(n):
            nochange[i][j] = dist[i][j]

    for k in xrange(n):
        for i in xrange(n):
            if nochange[i][k] > -1:
                for j in xrange(n):
                    if (i == j):
                        nochange[i][j] = -1
                    elif (nochange[k][j] > -1):
                        r = nochange[i][k] + nochange[k][j]
                        if (nochange[i][j] == -1 or nochange[i][j] > r):
                            nochange[i][j] = r

    change = [[-1] * n for i in xrange(n)]     
    for i in xrange(n):
        for j in xrange(n):
            if nochange[i][j] > e[i]:
                nochange[i][j] = -1
            if (nochange[i][j] > -1):
                change[i][j] = nochange[i][j] * 1.0 / s[i]

    for k in xrange(n):
        for i in xrange(n):
            for j in xrange(n):
                if (i != j and change[i][k] > -1 and change[k][j] > -1):
                    r = change[i][k] + change[k][j]
                    if (change[i][j] == -1 or r < change[i][j]):
                        change[i][j] = change[i][k] + change[k][j]
    #print nochange
    #print change

    ans = []
    for i in xrange(q):
        u, v = [int(g) for g in raw_input().split(" ")]
        ans.append(change[u-1][v-1])


    print "Case #{}: {}".format(K+1, " ".join([str(x) for x in ans]))