
from blist import sortedset

file_in = open('c.in', 'r')
file_out = open('c.out', 'w')

n_case = int(file_in.readline())

class X:
    def __init__(self, num, code):
        self.adj = set([])
        self.num = num
        self.code = code

def connect(x, y):
    x.adj.add(y)
    y.adj.add(x)
def disconnect(x, y):
    x.adj.discard(y)
    y.adj.discard(x)

for i_case in range(n_case):
    print i_case

    xs = []
    N, M = (int(s) for s in file_in.readline().split())
    for i in range(N):
        xs.append(X(i+1, int(file_in.readline())))
    for i in range(M):
        a, b = (int(s)-1 for s in file_in.readline().split())
        connect(xs[a], xs[b])

    start = min(xs, key=lambda x: x.code)
    retreated = set()
    stack = [start]
    ans = str(start.code)

    def is_connected():
        reachable = set()
        def flood(x):
            if x in reachable or x in retreated:
                return
            reachable.add(x)
            for y in x.adj:
                flood(y)
        flood(start)
        return len(reachable) + len(retreated) == N
        
    print "start", stack[-1].num
    for i_step in xrange(N - 1):
        options = []
        for parent in reversed(stack):
            options.extend(parent.adj - set(stack) - retreated)

            retreated.add(parent)
            if not is_connected():
                break
        retreated = retreated - set(stack)

        best = min(options, key=lambda x: x.code)
        while best not in stack[-1].adj:
            retreated.add(stack.pop())

        stack.append(best)
        print "visiting", best.num
        ans += str(best.code)
        

    file_out.write("Case #%d: %s\n" % (i_case + 1, ans))

file_in.close()
file_out.close()
