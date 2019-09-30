"""
Google Code Jam 2014 Round 1B Problem B

Author  : chaotic_iak
Language: Python 3.3.4
"""

class IOHandlerObject(object):
    source = "b.in"
    target = "b.out"
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

def breaktwo(n):
    s = ""
    while n:
        s = str(n%2) + s
        n //= 2
    s = ("0" * 30 + s)[-30:]
    res = []
    for i in range(30):
        if s[i] == "1": res.append(s[:i] + "0" + "_" * (30-i))
    res.append(s)
    return res

multipliers = {
    "000": 1,
    "001": 0,
    "00_": 1,
    "010": 1,
    "011": 0,
    "01_": 1,
    "0_0": 2,
    "0_1": 0,
    "0__": 2,
    "100": 1,
    "101": 0,
    "10_": 1,
    "110": 0,
    "111": 1,
    "11_": 1,
    "1_0": 1,
    "1_1": 1,
    "1__": 2,
    "_00": 2,
    "_01": 0,
    "_0_": 2,
    "_10": 1,
    "_11": 1,
    "_1_": 2,
    "__0": 3,
    "__1": 1,
    "___": 4
}

t, = g()
for qq in range(t):
    w("Case #" + str(qq+1) + ": ")
    a,b,k = g()
    a,b,k = breaktwo(a-1), breaktwo(b-1), breaktwo(k-1)
    ct = 0
    for at,bt,kt in itertools.product(a,b,k):
        tem = 1
        for i in range(30):
            ar = at[i]
            br = bt[i]
            kr = kt[i]
            tem *= multipliers[ar+br+kr]
        ct += tem
    w(str(ct))
    w()