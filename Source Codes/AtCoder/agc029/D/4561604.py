from collections import defaultdict
def inpl(): return list(map(int,input().split()))

class Counter:
    def __init__(self, start=0):
        self.index = start-1

    def __call__(self):
        self.index += 1
        return self.index

ui = defaultdict(Counter())
xylist = []

H, W, N = inpl()
for i in range(N):
    X, Y = inpl()
    n = ui[X]
    if n < len(xylist):
        xylist[n][1] = min(xylist[n][1],Y)
    else:
        xylist.append([X,Y])

xylist.sort(key=lambda x: x[0])
xylist.append([H+1,1])

Xprev = Yprev = 1
for X, Y in xylist:
    Ybound = Yprev + X - Xprev 
    if Y < Ybound:
        ans = X - 1
        break
    elif Y == Ybound:
        Xprev, Yprev = X, Ybound - 1
    else:
        Xprev, Yprev = X, Ybound

print(ans)