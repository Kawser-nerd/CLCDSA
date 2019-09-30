##            
## PROBLEM SOLVING ALGORITHM 
##  
def solve(n,c,m,tickets):

    ticketsPerCustomer = [[item[1] for item in tickets].count(i+1) for i in range(c)]
    ticketsPerSeat = [[item[0] for item in tickets].count(i+1) for i in range(n)]

    #print(str(ticketsPerSeat))
    
    # determine minimum number of rides
    minRides = max(ticketsPerCustomer)
    s = 0
    for i in range(n):
        # print("min rides="+str(minRides))
        s += ticketsPerSeat[i]
        if s>minRides*(i+1):
            minRides = (s-1)//(i+1)+1

    # now number of promotions
    promotions = sum([max(0,item - minRides) for item in ticketsPerSeat])

    return str(minRides)+" "+str(promotions)
                    
##            
## MAIN LOOP: read(from stdin) - solve - print(to stdout) 
##
for t in range(int(input())):
    
    ## read case
    n,c,m = [int(item) for item in input().rstrip().split()]
    tickets = [[int(item) for item in input().rstrip().split()] for _ in range(m)]
        
    ## solve and print result
    result = solve(n,c,m,tickets)
    print('Case #'+str(t+1)+': '+str(result))
