inp = open("d:\\incoming\\a-large.in")
outp = open("d:\\incoming\\a.out", "w")

def go(tokens, here, features):
    ret = float(tokens[here + 1])
    if tokens[here + 2] == ")": return ret
    nexttree = here + 3
    if tokens[here + 2] not in features:
        #print "does not have %s" % tokens[here + 2]
        opened = 0
        while True:
            if tokens[nexttree] == "(":
                opened += 1
            elif tokens[nexttree] == ")":
                opened -= 1
            nexttree += 1
            if opened == 0:
                break
    else:
        pass
         #print "does have %s" % tokens[here + 2]

    return go(tokens, nexttree, features) * ret
                    

cases = int(inp.readline())
for cc in xrange(cases):
    print "Case #%d:" % (cc+1)
    outp.write("Case #%d:\n" % (cc+1))
    lines = int(inp.readline())
    desc = ""
    for i in xrange(lines):
        desc += inp.readline() + " "
    tokens = desc.replace("(", "( ").replace(")", " )").split()
    features = set()
    animals = int(inp.readline())
    for i in xrange(animals):
        has = set()
        tok = inp.readline().split()[2:]
        for x in tok:
            has.add(x)
        #print "%.10lf" % go(tokens, 0, has)
        outp.write("%.10lf\n" % go(tokens, 0, has))

outp.close()
