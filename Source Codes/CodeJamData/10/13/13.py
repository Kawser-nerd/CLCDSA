### Google Code Jam template
## Setup
# Task letter
TASK="C"

## Input templates
# Line as int
#int(infile.readline())
# Line as many ints
#(int(s) for s in infile.readline().split())

## Precalculation
print("Precalculation...")
NUM = 1000001
top = [0]*NUM
btm = [0]*NUM
cbtm = 0
for i in range(1, NUM):
    if top[cbtm] < i:
        cbtm += 1
    btm[i] = cbtm
    top[i] = cbtm + i
print("Precalculation done.")

## Calculation
with open(TASK+".in") as infile:
    with open(TASK+".out",mode="wt") as outfile:
        cases = int(infile.readline())
        for ncase in range(cases):
            # Perform all nessesary calculation
            A1, A2, B1, B2 = (int(s) for s in infile.readline().split())
            #if A2 - A1 > B2 - B1:
            #    A1, A2 = A2, A1
            #    B1, B2 = B2, B1
            lost = 0
            print("Now:", ncase+1)
            for i in range(A1, A2+1):
                b = max(B1, btm[i-1]+1)
                t = min(B2, top[i-1]+1)
                lost += max(0, t-b+1)
            outfile.write("Case #{nc}: {data}\n".format(nc=ncase+1,data=(A2-A1+1)*(B2-B1+1)-lost))
print("Ready")
