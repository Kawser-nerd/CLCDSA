class Case:
    def __init__(self, fin, fout, n):
        self._fin = fin
        self._fout = fout
        self._n = n
        self._line = None

    def readInt(self):
        if self._line is None:
            self._line = self._fin.readline().split(" ")
        result = int(self._line.pop(0))
        if len(self._line) == 0:
            self._line = None
        return result

    def readLine(self):
        line = self._fin.readline()
        if line[-1] == "\n":
            return line[:-1]
        return line
    
    def output(self, s):
        if s is None:
            return
        s = str(s)
        if "\n" in s:
            self._fout.write("Case #%d:%s" % (self._n,s ))
        else:
            self._fout.write("Case #%d: %s\n" % (self._n, s))

def run(fileName, solve):
    fin = open(fileName)
    fout = open(fileName + ".out", "w")
    caseCount = int(fin.readline())
    for i in range(caseCount):
        case = Case(fin, fout, i + 1)
        case.output(solve(case))
