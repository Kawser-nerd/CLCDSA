# Python 3.2

import sys

infile = None
outfile = None

def readline():
    x = infile.readline()
    if len(x) > 0:
        return x[:-1] # remove trailing endline
    else:
        return x

def readint():
    return int(readline())

def readfloat():
    return float(readline())

def readints():
    xs = readline().split()
    return [int(x) for x in xs]

def readfloats():
    xs = readline().split()
    return [float(x) for x in xs]

def writeline(x):
    outfile.write(x + '\n')

def run(main):
    global infile, outfile
    args = sys.argv

    if len(args) == 1:
        infile = sys.stdin
        outfile = sys.stdout
    elif len(args) == 2:
        if args[1] == '-':
            infile = sys.stdin
        else:
            infile = open(args[1], 'r')

        if args[1].endswith('.in'):
            outfile = open(args[1][:-3] + '.out', 'w')
        else:
            outfile = sys.stdout
    elif len(args) == 3:
        if args[1] == '-':
            infile = sys.stdin
        else:
            infile = open(args[1], 'r')

        if args[2] == '-':
            outfile = sys.stdout
        else:
            outfile = open(args[2], 'w')
    else:
        print ("Expected 0, 1, or 2 args, not {:d}".format(len(args) - 1))
        print (args)
        return

    t = readint()

    for casenum in range(1, t + 1):
        main(casenum)

    if infile is not sys.stdin:
        infile.close()
    if outfile is not sys.stdout:
        outfile.close()
