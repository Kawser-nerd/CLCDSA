import sys

infile = None
outfile = None

def readline():
    x = infile.readline()
    if len(x) > 0 and x[-1] == '\n':
        return x[:-1]
    else:
        return x

def readint():
    return int(readline())

def readfloat():
    return float(readline())

def readints():
    return [int(x) for x in readline().split()]

def readfloats():
    return [float(x) for x in readline().split()]

def writeline(x):
    outfile.write(x + '\n')

def writecase(casenum, answer):
    outfile.write('Case #{:d}: {}\n'.format(casenum, answer))

def run(main):
    global infile, outfile
    args = sys.argv

    infile = sys.stdin
    outfile = sys.stdout

    if len(args) == 2:
        if args[1] != '-':
            infile = open(args[1], 'r')
            if args[1].endswith('.in'):
                outfile = open(args[1][:-3] + '.out', 'w')
    elif len(args) == 3:
        if args[1] != '-':
            infile = open(args[1], 'r')
        if args[2] != '-':
            outfile = open(args[2], 'w')
    elif len(args) > 3:
        print ("Expected 0, 1, or 2 arguments, not {}".format(len(args) - 1))
        print (args)
        return

    t = readint()

    for casenum in range(1, t + 1):
        main(casenum)

    if infile is not sys.stdin:
        infile.close()
    if outfile is not sys.stdout:
        outfile.close()
