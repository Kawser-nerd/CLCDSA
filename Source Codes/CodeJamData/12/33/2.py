import sys

class Memoize:
    def __init__(self, f):
        self.f = f
        self.memo = {}
    def __call__(self, *args):
        if not args in self.memo:
            self.memo[args] = self.f(*args)
        return self.memo[args]

def solve(Ai, Bi, Aused, Bused):
    if Ai >= len(Act) or Bi >= len(Bct):
        return 0
    elif Act[Ai][1] == Bct[Bi][1]:
        used = min(Act[Ai][0] - Aused, Bct[Bi][0] - Bused)
        Aused += used
        Bused += used
        if Aused == Act[Ai][0]:
            Ai += 1
            Aused = 0
        if Bused == Bct[Bi][0]:
            Bi += 1
            Bused = 0
        return used + solve(Ai, Bi, Aused, Bused)
    else:
        return max(solve(Ai + 1, Bi, 0, Bused), solve(Ai, Bi + 1, Aused, 0))

C = int(sys.stdin.readline())
solve = Memoize(solve)
for c in range(C):
    N, M = map(int, sys.stdin.readline().split())
    A = map(int, sys.stdin.readline().split())
    Act = zip(A[0:len(A):2], A[1:len(A):2])
    B = map(int, sys.stdin.readline().split())
    Bct = zip(B[0:len(B):2], B[1:len(B):2])
    solve.memo = {}
    y = solve(0, 0, 0, 0)
    print "Case #%d: %d" % (c + 1, y)
