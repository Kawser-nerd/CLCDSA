
import math

def C(k,a):
    if a == 0:
        return 1
    #print math.factorial(k)
    #print math.factorial(a)
    #print math.factorial(k-a)
    return math.factorial(k)/(math.factorial(a)*math.factorial(k-a))

def Cal(k,a):
    sum = 0
    for i in range(a,k+1):
        #print(i)
        sum += C(k,i)
    return sum * 1.0 / 2**k

T = int(raw_input())
for i in range(1,T+1):
    
    input = raw_input()
    b = input.split(" ")
    c = [int(e) for e in b]
    N = c[0]
    X = c[1]
    Y = c[2]
    if X < 0:
        X = -X
    if (X+Y)%2 == 1:
        p = 0
    elif X+Y == 0:
        p = 1
    elif X == 0:
        level = Y/2 + 2
        btm = (2*level - 3) * (level - 1)
        if N >= btm:
            p = 1
        else:
            p = 0
    else:
        level = (X+Y)/2 + 1
        btm = (2*level - 3) * (level - 1) + Y + 1
        #print(btm)
        level2 = level+1
        upper = (2*level2 - 3) * (level2 - 1) - X
        #print(upper)
        if N < btm:
            p = 0
        elif N >= upper:
            p = 1
        else:
            left = N - (2*level - 3) * (level - 1);
            a = Y + 1
            p = Cal(left,a)
    print("Case #" + str(i) + ": " + str(p))