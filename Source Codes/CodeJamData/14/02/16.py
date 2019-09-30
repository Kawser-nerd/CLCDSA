memo = dict()

#when can I buy nth factory, assuming buying all
def canBuy(C,F,n):
    if (C,F,n) in memo:
        return memo[(C,F,n)]
    if n==1:
        return C / 2.0
    memo[(C,F,n)] = canBuy(C,F,n-1) + C/ (2.0 + F* (n-1))
    return canBuy(C,F,n)

def best(C,F,X):
    factories =0
    bestTime = X/2.0
    
    while True:
        factories+=1
        time = canBuy(C,F,factories)
        time += X / (factories* F + 2.)
        if time < bestTime:
            bestTime = time
        else:
            return bestTime
    

f = open('input.in' , 'r')
data = f.read().split('\n')

instances = int(data[0])
#print instances

for x in xrange(instances):
    line = map(float, data[x+1].split(" "))
    C, F, X = line[0], line[1], line[2]
    print "Case #%d: %.7f" % (x+1, best(C,F,X))


