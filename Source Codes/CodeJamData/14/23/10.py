"""
Google Code Jam 2014 Round 1B Problem C

Author  : chaotic_iak
Language: Python 3.3.4
"""

class IOHandlerObject(object):
    source = "c.in"
    target = "c.out"
    sfile = None
    tfile = None

    def __init__(self):
        self.sfile = open(self.source, "a+")
        self.sfile.seek(0)
        self.tfile = open(self.target, "w+")

    def getInput(self, mode=2):
        # 0: String
        # 1: List of strings
        # 2: List of integers
        inputs = self.sfile.readline().strip()
        if mode == 0:
            return inputs
        if mode == 1:
            return inputs.split()
        if mode == 2:
            return [int(x) for x in inputs.split()]

    def writeOutput(self, s="\n"):
        if isinstance(s, list): s = " ".join(s)
        self.tfile.write(s)

IOHandler = IOHandlerObject()
g = IOHandler.getInput
w = IOHandler.writeOutput

############################## SOLUTION ##############################
import itertools

t, = g()
for qq in range(t):
    w("Case #" + str(qq+1) + ": ")
    n,m = g()
    legend = [0] * n
    zipcodes = []
    adj = []
    for i in range(n):
        zipcodes.append((g(0), i))
        adj.append([])
    zipcodes.sort(key = lambda x: x[0])
    for i in range(n):
        legend[zipcodes[i][1]] = i
    for i in range(m):
        x = g()
        adj[legend[x[0]-1]].append(legend[x[1]-1])
        adj[legend[x[1]-1]].append(legend[x[0]-1])
    perm = itertools.permutations(range(n))
    for p in perm:
        stack = [p[0]]
        for i in p:
            if i == p[0]: continue
            while stack:
                if i in adj[stack[-1]]:
                    stack.append(i)
                    break
                else:
                    stack.pop()
            if not stack: break
        if stack:
            res = ""
            for i in p:
                res += zipcodes[i][0]
            w(res)
            break
    w()