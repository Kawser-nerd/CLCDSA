import sys, os

in_file = None
out_file = None

def run_main(main):
    name = sys.argv[0][:-3]
    in_file_name = name + ".in"
    out_file_name = name + ".out"
    if len(sys.argv) == 2:
        in_file_name = sys.argv[1]
        out_file_name = in_file_name[:-3] + ".out"
    if len(sys.argv) == 3:
        if sys.argv[1]:
            in_file_name = sys.argv[1]
        if sys.argv[2]:
            out_file_name = sys.argv[2]

    global in_file
    global out_file
    
    if in_file_name == '-':
        in_file = sys.stdin
    else:
        in_file = open(in_file_name, 'r')

    if out_file_name == '-':
        out_file = sys.stdout
    else:
        out_file = open(out_file_name, 'w')

    main(in_file, out_file)

    out_file.close()
    in_file.close()

def run_tests(do_testcase):
    def main(in_file, out_file):
        t = readinteger()
        for x in xrange(t):
            do_testcase(x + 1)
    run_main(main)

def readline():
    return in_file.readline()[:-1]

def writeline(s):
    out_file.write("%s\n" % s)

def readinteger():
    return int(readline())

def readintegers():
    integers = readline().split()
    for i in xrange(len(integers)):
        integers[i] = int(integers[i])
    return integers
