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
    C, N = case
    combTable = combNumberTable(C)
    p = [0.0] * (C+1)
    p[0] = 1.0
    k = 0

    E = 0
    while True:
#        print "round", k , p
        k += 1
        newp = [0]*(C+1)
        for n in range(C+1):
            for i in range(n+1):
                newp[n] += p[i]*(combTable[C-i][n-i]*combTable[i][N+i-n])/combTable[C][N]
        err = (newp[C]-p[C])*k
        if k > 100 and err < 0.00000001:
            return E
        else:
            E += err
            p = newp

def combNumberTable(N):
    result = [[1]*(N+1) for _ in range(N+1)]
    for n in range(N+1):
        for m in range(n+1, N+1):
            result[n][m] = 0
    for n in range(N+1):
        for m in range(n):
            result[n][m] = result[n-1][m] + result[n-1][m-1]
    return result
    
#5. format solution to string
def solution2str(solution):
    return "%8f" % solution

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
        print combNumberTable(10)
