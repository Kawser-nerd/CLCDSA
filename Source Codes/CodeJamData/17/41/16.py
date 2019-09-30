##            
## PROBLEM SOLVING ALGORITHM 
##  
def solve(n,p,g):
    leftOvers = [item % p for item in g]
    count = [leftOvers.count(i) for i in range(p)]

    res = count[0]

    if p==2:
        return res + (count[1]+1)//2

    if p==3:
        m = min(count[1],count[2])
        res += m
        m = max(count[1],count[2]) - m
        res += (m//3)
        if m%3>0:
            res += 1
        return res
        
    # p==4 
    m = min(count[1],count[3])
    res += m
    count[1] -= m
    count[3] -= m
    
    res += count[2]//2
    count[2] = count[2] % 2

    m = min(count[1]//2,count[2])
    res += m
    count[1] -= 2*m
    count[2] -= m
    
    m = min(count[3]//2,count[2])
    res += m
    count[3] -= 2*m
    count[2] -= m

    m = sum(count[1:4])
    res += (m//4)
    if m%4>0:
        res += 1
        
    return res

                    
##            
## MAIN LOOP: read(from stdin) - solve - print(to stdout) 
##
for t in range(int(input())):
    
    ## read case
    n,p = [int(item) for item in input().rstrip().split()]
    g = [int(item) for item in input().rstrip().split()]
    
    ## solve and print result
    result = solve(n,p,g)
    print('Case #'+str(t+1)+': '+str(result))
