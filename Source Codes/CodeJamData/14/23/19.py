import itertools

T = input()


def get(order, edge, N, postal):
    q = []
    q.append(order[0])

    for i in range(len(order)-1):
        while q:
            if order[i+1] in edge[q[-1]]:
                q.append(order[i+1])
                break
            else:
                q.pop()
        if not q:
            return None
    return ''.join(str(postal[x]) for x in order)


for t in range(1, T+1):
    N, M = map(int, raw_input().split())
    postal = ['']
    edge = {}
    visit = set()

    for i in range(N):
        postal.append(int(raw_input()))
        edge[i+1] = []

    for i in range(M):
        a, b = map(int, raw_input().split())
        edge[a].append(b)
        edge[b].append(a)

    for i in range(1, N+1):
        edge[i].sort(key=lambda x: postal[x])

    minstr = '999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999'
    for perm in itertools.permutations(range(1, N+1)):
        p = get(perm, edge, N, postal)
        if p is None:
            continue

        if p < minstr:
            minstr = p

    print 'Case #%d:' % t, minstr
