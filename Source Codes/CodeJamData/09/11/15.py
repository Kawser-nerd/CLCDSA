import psyco
psyco.full()

#1. output format
sepInOutput = " "

#2. read problem setup
def readProblemSetup(fi):
    # read problem parameters
    result = map(int, fi.readline().split())
    # read other things

    # return as a tuple
    return result

#3. read problem case
def readCase(fi):
    # read one case
    return map(int, fi.readline().split())

#4. solve case
def solveCase(case, setup):
    # solve the case
    i = 2
    while True:
        flag = True
        for base in case:
            if happyp(i, base) == 0:
                print "dada: n = %d, base = %d" % (i, base)
            elif happyp(i, base) == -1:
                flag = False
                break
        if flag:
            return i
        else:
            i += 1

def squareofdigits(n, base):
    sum = 0
    while n > 0:
        n, r = divmod(n, base)
        sum += r*r
    return sum

def happyp(n, base, mtry=1000):
    seen = set([n])
    k = 1
    while k < mtry:
        if n == 1:
            return 1
        else:
            n = squareofdigits(n, base)
            if n in seen:
                return -1
            else:
                seen.add(n)
        k += 1
    return 0

#5. format solution to string
def solution2str(solution):
    return str(solution)

def solveFile(f, f2):
    fi = open(f, 'r')
    if f2 == None:
        fo = sys.stdout
    else:
        fo = open(f2, 'w')
    # 1. read problem setup if needed
    setup = readProblemSetup(fi)

    N = setup[0]
    # 2. solve the cases
    for i in range(1, N+1):
        fo.write("Case #%d:%s%s\n" % (i, sepInOutput,
                                    solution2str(solveCase(readCase(fi), setup))))
if __name__=='__main__':
    import sys
    if len(sys.argv) == 2:
        solveFile(sys.argv[1], sys.argv[1]+".out")
    elif len(sys.argv) == 3:
        solveFile(sys.argv[1], None)
    else:
        # run tests
        print "running tests:"
        print "10, 3:", squareofdigits(10, 3)
        print "10, 2:", squareofdigits(10, 2)
