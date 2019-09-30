import itertools
T = int(raw_input())

for case in xrange(1, T+1):
    N, M = map(int, raw_input().split())
    U = map(lambda x: int(x)-1, raw_input().split())
    V = map(lambda x: int(x)-1, raw_input().split())

    roomvertices = [set(range(N))]
    corner_rooms = {}
    for i in xrange(N):
        corner_rooms[i] = set([0])

    for i in xrange(M):
        room = (corner_rooms[V[i]].intersection(corner_rooms[U[i]])).pop()

        oldvertices = roomvertices[room]
        newvertices = set()
        newvertices.add(U[i])
        newvertices.add(V[i])

        cur = (U[i]+1)%N
        while cur != V[i]:
            if cur in oldvertices:
                oldvertices.remove(cur)
                newvertices.add(cur)
            cur = (cur+1)%N

        roomvertices.append(newvertices)
        for vertices in newvertices:
            corner_rooms[vertices].remove(room)
            corner_rooms[vertices].add(len(roomvertices)-1)
        corner_rooms[U[i]].add(room)
        corner_rooms[V[i]].add(room)

    maxC = min(map(len, roomvertices))
    ansC = -1
    ans = False

    for i in xrange(maxC, 0, -1):
        for p in itertools.product(range(i), repeat=N):
            valid = True
            for room in roomvertices:
                t = 0
                for v in room:
                    t |= 1<<p[v]
                if t != (1<<i)-1:
                    valid = False
                    break
            if valid:
                ansC = i
                ans = p
        if ansC != -1:
            break
    print "Case #%d: %d" % (case, ansC)
    print " ".join(map(lambda x: str(x+1), ans))
