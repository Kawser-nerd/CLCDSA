import sys

class Reader:
    def __init__(self, filename):
        self.fp = open(filename)
    
    def readline(self):
        return [int(x) for x in self.fp.readline().split()]

reader = Reader(sys.argv[1])
cases, = reader.readline()
for case in range(cases):
    n, k = reader.readline()
    mask = (1 << n) - 1
    on = (((k + 1) & mask) == 0)
    print "Case #%d: %s" % (case + 1, 'ON' if on else 'OFF')
