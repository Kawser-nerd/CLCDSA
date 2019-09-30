import heapq

def alphabet(n, z):
    coins = 0
    turns = 0
    coined = [0]*n
    while coins < 2*n:
        won = False
        for i in xrange(n):
            if z[i][1] <= coins and coined[i] < 2:
                won = True
                coins += 2-coined[i]
                #print str(i)+" get "+str(2-coined[i])
                coined[i] = 2
                turns += 1
        if not won:
            maxi = -1
            maxm = -1
            for i in xrange(n):
                if coined[i] == 0 and z[i][0] <= coins and z[i][1] > maxm:
                    maxm = z[i][1]
                    maxi = i
            if maxm == -1:
                return -1
            else:
                coined[maxi] = 1
                #print str(maxi)+" get failure 1"
                coins += 1
                turns += 1
        #print "----"+str(coins)+"/"+str(2*n)
    return turns

if __name__ == "__main__":
    fn = open("B-large.in","r")
    tcase = int(fn.readline())
    for x in range(tcase):
        a = int(fn.readline())
        l = []
        for i in xrange(a):
            kk = fn.readline().split()
            l.append((int(kk[0]),int(kk[1])))
        yy = alphabet(a,l)
        if yy == -1:
            print "Case #%d: Too Bad" % (x+1)
        else:
            print "Case #%d: %d" % (x+1, yy)
