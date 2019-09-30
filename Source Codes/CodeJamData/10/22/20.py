import sys

def chasing_chicks(N, K, B, T, Xs, Vs):
    
    #print N, K, B, T, Xs, Vs
    
    possible = []
    
    for x, v in zip(Xs, Vs):
        t = float(B - x)/v
    #    print 'time taken', t, T
        if t <= T:
            #print 'is possible'
            possible.append(True)
        else:
            possible.append(False)
    
    if len(filter(lambda x: x, possible)) < K:
        return 'IMPOSSIBLE'
    
    inters = []
    for i in range(N):
        inters.append([-1] * N)
    
    for i in range(N):
        for j in range(N):
            #print i, j
            if Vs[i] == Vs[j]:
                inters[i][j] = -1
            elif Xs[i] <= Xs[j]:
                inters[i][j] = -float((Xs[i] - Xs[j]))/float((Vs[i] - Vs[j]))
    
    costs = [0] * N
    for j in range(N):
        if not possible[j]:
            costs[j] = 9999999999999999999999999999999
    
    for i in range(N):
        for j in range(N):
            if inters[i][j] >= 0.0 and inters[i][j] < T:
                if not possible[j]:
                    costs[i] += 1
    
    costs.sort()
    return sum(costs[:K])

if __name__ == '__main__':
    ntests = int(sys.stdin.readline())
    for i in range(1, ntests+1):
        N, K, B, T = map(int, sys.stdin.readline().split())
        Xs = map(int, sys.stdin.readline().split())
        Vs = map(int, sys.stdin.readline().split())
        ans = chasing_chicks(N, K, B, T, Xs, Vs)
        print 'Case #%s: %s' %  (i, ans)
