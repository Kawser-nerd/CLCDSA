import math

N = int(input())
NUM =[]
CNUM =[]
M = N
flg = 0
for i in range(2,10*5):
    x = 0
    if N%i == 0:
        flg = 1
        NUM.append(i)
        while N%i == 0:
            N = N / i
            x += 1
        CNUM.append(x)
if(N > 10*5):
    NUM.append(N)
    CNUM.append(1)
if(flg == 0):
    print("Deficient")
    quit()
ANS = 1
for i in range(len(NUM)):
    CL = 0
    for j in range(CNUM[i]+1):
        CL += math.pow(NUM[i],j)
    ANS *= CL
ANS -= M
if(ANS == M):
    print("Perfect")
elif(ANS > M ):
    print("Abundant")
else:   
    print("Deficient")