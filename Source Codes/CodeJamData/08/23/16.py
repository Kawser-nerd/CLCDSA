from math import sqrt, sin, cos, asin, acos

class Case:
    def __init__(self, s):
        self.exp = int(s.read())

    def solve(self):
        x = 3.0 + sqrt(5.0)
        x10 = x / 10.0
        angle = acos(x10)        
        dp = [1 for i in range(31)]
        dp[1] = x % 1000
        dp[2] = x * x % 1000
        for i in range(1, 31):
            if dp[i] == 1:
                dp[i] = dp[i - 1] * x
                j = i * 2
                while j <= 31:
                    dp[j] = dp[i] * 100.0 * ((1.0 + cos(2.0 * angle)) / 2.0)
                    j *= 2
        return "%03d" % (dp[self.exp] % 1000)

class Contents:
    def __init__(self, f):
        self.data = [line.strip() for line in f]
        self.i = 0

    def read(self):
        return self.readList(1)[0]

    def readList(self, len):
        result = self.data[self.i : self.i + len]
        self.i += len
        return result

import sys
f = file(sys.argv[1])
s = Contents(f)
numCases = int(s.read())

for caseNum in range(numCases):
    case = Case(s)
    print "Case #%d: %s" % (caseNum + 1, case.solve())
