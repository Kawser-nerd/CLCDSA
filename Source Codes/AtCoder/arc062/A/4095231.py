# ABC 062
def getInt(): return int(input())
def getIntList(): return [int(x) for x in input().split()]
def zeros(n): return [0]*n
def db(x): 
    global debug
    if debug: print(x)
debug = False
N = getInt()
TA = zeros(N)
for i in range(N):
    TA[i] = getIntList()
db(TA)
real = TA[0]
for i in range(1,N):
#    if real[0]>real[1]:
    if real[0]/TA[i][0] > real[1]/TA[i][1]:
        lc = (real[0]+TA[i][0]-1)//TA[i][0]*TA[i][0]
        real[0] = lc 
        real[1] = lc * TA[i][1] // TA[i][0]  
    else:
        lc = (real[1]+TA[i][1]-1)//TA[i][1]*TA[i][1]
        real[1] = lc 
        real[0] = lc * TA[i][0] // TA[i][1]  
    db((lc,real))
print(sum(real))