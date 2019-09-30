def getint(file): return int(file.readline().strip())
def getstr(file): return file.readline().strip()

def run_file(file):
    if isinstance(file, basestring): file = open(file)
    ncases = getint(file)
    cases = []
    for case in xrange(ncases):
        nengines = getint(file)
        engines = [getstr(file) for i in xrange(nengines)]
        nsearches = getint(file)
        searches = [getstr(file) for i in xrange(nsearches)]
        print "Case #%d: %d" % (case+1, run_case(engines, searches))

def run_case(engines, searches):
    # Pick an engine that runs for the longest before requiring a switch.
    # Switching early accomplishes nothing!
    nswitches = 0
    while True:
        best = None
        for engine in engines:
            if engine not in searches: return nswitches
            found = searches.index(engine)
            remain = searches[found:]
            if best is None or len(remain) < len(best): best = remain
        assert best is not None
        searches = best
        nswitches += 1

if __name__ == '__main__':
    import sys
    if len(sys.argv) > 1: run_file(sys.argv[1])
    else: run_file(sys.stdin)

