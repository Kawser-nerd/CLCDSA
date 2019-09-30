import sys

fileName = "C-large"
sys.stdin = open(fileName+".in", 'r')
output = open(fileName+".out", 'w')
T = int(input())
for case in range(1,T+1):

    S = input()
    print("S = "+S)
    N,K = S.split(" ")
    N,K = int(N),int(K)
    print("N = "+str(N))
    print("K = "+str(K))

    moves = 0
    gapSize = [N]
    gapNumber = {}
    gapNumber[N] = 1
    size = 0
    done = False
    while not done:
        #print(gapSize)
        m = gapSize.pop(0)
        n = gapNumber[m]
        if n+moves>=K:
            size=m
            done = True
        else:
            moves+=n
            for a in [m//2,(m-1)//2]:
                if a in gapNumber:
                    gapNumber[a]+=n
                else:
                    gapNumber[a]=n
                    gapSize.append(a)
    answer = str(size//2)+" "+str((size-1)//2)

    ######################################################################
    print("Case #%d:" % case, answer)
    print("Case #%d:" % case, answer, file = output)
    ######################################################################
