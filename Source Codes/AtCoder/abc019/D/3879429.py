import sys
input=sys.stdin.readline
def fQ(i:int,i2:int):
    sys.stdout.write(" ".join(("?",str(i),str(i2))))
    sys.stdout.write("\n")
    sys.stdout.flush()

#??????????????????

N = int(input())
dMax = 0
iP = 0
for i in range(2,N+1):
    fQ(1,i)
    d = int(input())
    if dMax < d:
        dMax = d
        iP = i
for i in range(1,N+1):
    if i == iP:
        continue
    else:
        fQ(iP,i)
        d = int(input())
        if dMax < d:
            dMax = d
print("!",dMax)