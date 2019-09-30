import sys

fileName = "B-large"
sys.stdin = open(fileName+".in", 'r')
output = open(fileName+".out", 'w')
T = int(input())
for case in range(1,T+1):

    S = input()
    print("S = "+S)
    D = [int(n) for n in S]

    isTidy = True
    for i in range(1,len(D)):
        if D[i]<D[i-1]:
            isTidy=False
    if isTidy:
        answer = S
        ######################################################################
        print("Case #%d:" % case, answer)
        print("Case #%d:" % case, answer, file = output)
        ######################################################################
    else:
        D = [0]+D[:]
        i=1
        while D[i]>=D[i-1]:
            i+=1
        j=i-1
        while D[j]==D[j-1]:
            j-=1
        E = D[:j] + [D[j]-1] + [9]*(len(D)-j-1)
        answer = 0
        for n in E:
            answer*=10
            answer+=n
        answer = str(answer)
        ######################################################################
        print("Case #%d:" % case, answer)
        print("Case #%d:" % case, answer, file = output)
        ######################################################################
