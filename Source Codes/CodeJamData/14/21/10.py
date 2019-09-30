"""
Google Code Jam 2014 Round 1B Problem A

Author  : chaotic_iak
Language: Python 3.3.4
"""

class IOHandlerObject(object):
    source = "a.in"
    target = "a.out"
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
def unique(s):
    a = s[0]
    i = 1
    while i < len(s):
        if a[-1] != s[i]: a += s[i]
        i += 1
    return a

def counts(s):
    a = [1]
    i = 1
    while i < len(s):
        if s[i-1] == s[i]:
            a[-1] += 1
        else:
            a.append(1)
        i += 1
    return a

t,=g()
for i in range(t):
    w("Case #" + str(i+1) + ": ")
    n, = g()
    s = []
    for j in range(n):
        s.append(g(0))
    x = unique(s[0])
    if any(unique(i) != x for i in s):
        w("Fegla Won")
    else:
        st = [counts(x) for x in s]
        d = []
        for j in range(len(st[0])):
            d.append([])
            for k in range(n):
                d[-1].append(st[k][j])
        sm = 0
        for j in d:
            sm += min([sum(abs(m-nn) for m in j) for nn in range(101)])
        w(str(sm))
    w()