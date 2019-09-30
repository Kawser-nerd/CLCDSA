task = 'C'
type = 2

if type == 0:
    inp = open('sample.in', 'r')
elif type == 1:
    inp = open('%s-small.in' % (task,))
else:
    inp = open('%s-large.in' % (task), )
outp = open('%s.out' % (task,), 'w')

T = int(inp.readline()[:-1])
for t in range(T):

    N = int(inp.readline()[:-1])
    edges = [-1 for i in range(N)]
    revedges = [list() for i in range(N)]
    st = inp.readline()[:-1].split()


    def dfs(v):
        anses = [0]
        for v2 in revedges[v]:
            anses.append(dfs(v2) + 1)
        return max(anses)


    for j, a in zip(range(N), st):
        a = int(a) - 1
        edges[j] = a
        revedges[a].append(j)
    pairs = set()
    loncyc = 0
    for i in range(N):
        used = [-1 for i in range(N)]
        cur = i
        curs = 0
        while used[cur] == -1:
            used[cur] = curs
            curs += 1
            cur = edges[cur]
        if curs - used[cur] == 2:
            pairs.add(cur)
        loncyc = max(loncyc, curs - used[cur])
    pairtokens_sum = 0
    while len(pairs) > 0:
        cur1 = pairs.pop()
        cur2 = edges[cur1]
        revedges[cur1].remove(cur2)
        revedges[cur2].remove(cur1)
        pairs.remove(cur2)
        curs = 2+ dfs(cur1) + dfs(cur2)
        pairtokens_sum += curs
    ans = max(pairtokens_sum, loncyc)
    outp.write("Case #%s: %s\n" % (t + 1, ans))
