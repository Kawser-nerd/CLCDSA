from sys import stdin

def trimmed(E, v, u):
    t = sorted([ trimmed(E, n, v) for n in E[v] if n is not u ])
    if len(t)<=1:
        return 1
    else:
        return 1 + t[-2] + t[-1]

T = int(stdin.readline())
for t in range(1,T+1):
    N = int(stdin.readline())
    E = [list() for v in range(N)]

    for e in range(N-1):
        a, b = [int(word)-1 for word in stdin.readline().strip().split()]
        E[a].append(b)
        E[b].append(a)

    min_trim = N
    for root in range(N):
        min_trim = min(min_trim, N - trimmed(E, root, None) )

    print "Case #"+str(t)+":",
    print min_trim
