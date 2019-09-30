from collections import defaultdict
def solve(N, C, M, A):
    num_bought = defaultdict(int)
    for p,b in A:
        num_bought[b] += 1
    
    tickets = defaultdict(list)
    for p, b in A:
        tickets[p].append(b)
    for k,v in tickets.iteritems():
        v.sort(key = lambda x: num_bought[x])

    R = max(num_bought.values())
    tickets_sold = len(A)
    #Lets guess that there are going to be R...tickets_sold rides
    for num_rides in xrange(R, tickets_sold + 1):
        #Sit everyone down.  You know some seat is oversold
        #when len(tickets[p]) > num_rides, so we must promote that
        promos = 0
        awaiting_seat = 0
        for seat in xrange(N, 0, -1):
            new = len(tickets[seat])
            if awaiting_seat + new <= num_rides:
                awaiting_seat = 0
            else:
                #seat all new first
                if new <= num_rides:
                    rem = num_rides - new
                    awaiting_seat -= rem
                    awaiting_seat = max(awaiting_seat, 0)
                else:
                    awaiting_seat += (new - num_rides)
                    promos += new - num_rides

        if not awaiting_seat:
            return "{} {}".format(num_rides, promos)
        
    """
    ans = 0
    todo = len(A)
    while todo:
        #initially fill the trolley
        ride = [0] * (N+1)
        #0 seat is dummy
        for seat in xrange(N, 0, -1):
            if tickets[seat]:
                ride[seat] = tickets[seat].pop()
    """ 
    

###
def main():
    with open('in.txt','r') as fi, \
            open('out.txt', 'w') as fo:
        rr = lambda: fi.readline().strip()
        rrM = lambda: map(int,rr().split())
        for tc in xrange(1, 1 + int(rr())):
            N, C, M = rrM()
            A = [rrM() for _ in xrange(M)]
            zeta = solve(N, C, M, A)
            outstr = "Case #%i: " % tc + str(zeta)
            print outstr
            fo.write(outstr+'\n')
            
if __name__ == "__main__": main()
