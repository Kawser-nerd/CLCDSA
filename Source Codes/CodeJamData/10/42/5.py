
def mincost(prices, rnd, M, P):
    res = 0
    #print "Round", rnd
    #print M
    for num in range(2**(P-rnd)):
        # calculate whether or not we need to buy here
        buy = False
        for i in range(len(M)):
            #print int(i / 2**rnd)
            if int(i / 2**rnd) == num:
                if M[i] < P:
                    buy = True
                    break;
        if buy:
            #print "buy"
            res += prices[rnd-1][num]
            for i in range(len(M)):
                #print int(i / 2**rnd)
                if int(i / 2**rnd) == num:
                    M[i] += 1
    if (rnd > 1):
        res += mincost(prices, rnd-1, M, P)
    #print res
    return res


infile = open("B-small.in", "r")

T = int(infile.readline().strip())

for t in range(T):
    prices = []
    P = int(infile.readline().strip())
    M = eval("["+infile.readline().strip().replace(' ',',')+"]")
    for p in range(P):
        arr = eval("["+infile.readline().strip().replace(' ',',')+"]")
        prices.append(arr)
    answer = mincost(prices, P, M, P)
    print "Case #" + str(t+1) + ": " + str(answer)
    
