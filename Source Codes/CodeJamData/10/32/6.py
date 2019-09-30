import math
T=int(input())

for testCase in range(0,T):
    line=input().split()
    L=int(line[0])
    P=int(line[1])
    C=int(line[2])
    a=math.log(P/L,C)
    a=math.ceil(a)
    b=math.ceil(math.log(a,2))
    print('Case #{0}: {1}'.format(testCase+1, b))
