import sys

##            
## PROBLEM SOLVING ALGORITHM 
##  
def solve(w,h,b,coordinates):
    river = [[False for _ in range(w)] for _ in range(h)]

    ## mark buildings 
    for x0,y0,x1,y1 in coordinates:
        for x in range(x0,x1+1):
            for y in range(y0,y1+1):
                river[y][x] = True

    ## now search pathes through river
    flow = 0
    dirs = [(1,0),(0,1),(-1,0),(0,-1)]

    for xs in range(w):

        ## start at 0,xs
        ways = [(0,xs,0)]

        while ways!=[]:
            (y,x,lastDir) = ways.pop()
            
            if river[y][x]==False:
                river[y][x] = True

                ## if gone through, abort
                ## and start with next field with incoming flow
                if y==h-1:
                    flow += 1
                    break

                ## 4 possibilities of flow
                ## follow 'hand at left wall' strategy
                for d in range(4):
                    d2 = (lastDir+6-d)%4
                    dy,dx = dirs[d2]
                    if 0<=y+dy and 0<=x+dx<w:
                        ways.append((y+dy,x+dx,d2))
                    
    return flow

##            
## MAIN LOOP: read(from stdin) - solve - print(to stdout) 
##
T = int(input())
for t in range(T):
    
    ## read case
    w,h,b = [int(item) for item in input().rstrip().split()]
    coordinates = [[int(item) for item in input().rstrip().split()]
                    for _ in range(b)]
    
    ## solve and print result
    result = solve(w,h,b,coordinates)
    print('Case #'+str(t+1)+': '+str(result))

    ## progress output
    print('Done: '+str(t+1)+' of '+str(T), file=sys.stderr)
