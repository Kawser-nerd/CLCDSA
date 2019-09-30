tc = int(input())

for t in range(1, tc+1):
    print("Case #%d: "%t, end = "")
    n, p = map(int, input().split())
    reqs = list(map(int, input().split()))
    pls = []
    for _ in range(n):
        pls.append(list(map(int, input().split())))
    events = []
    for i in range(n):
        for j in range(p):
            u = pls[i][j]
            req = reqs[i]
            up = (10 * u) // (9 * req)
            down = (10 * u + 11 * req - 1) // (11 * req)
            if down == 0: down = 1
            if up < down: continue
            events.append((down, False, i, u, j))
            events.append((up, True, i, u, j))
    events.sort()
    #print(events)
    cnt = 0
    counts = [[] for _ in range(n)]
    remv = [0] * n
    for (bd, ev, i, yy, j) in events:
        #print(counts, remv)
        if ev:
            if remv[i] > 0:
                remv[i] -= 1
            #elif yy in counts[i]:
            else:
                counts[i].remove(yy)
        else:
            counts[i].append(yy)
            if all(counts):
                cnt += 1
                for ii in range(n):
                    counts[ii].remove(min(counts[ii]))
                    remv[ii] += 1
    print(cnt)
    
