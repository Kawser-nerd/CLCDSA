

def solve(testnum):
    n,m,k = [int(x) for x in input().split()]
    def valid(pt):
        return 0 <= pt[0] < m and 0 <= pt[1] < n
    
    board = [[False for x in range(m)] for y in range(n)]
    x,y = m//2,n//2
    board[y][x] = True
    perimeter = [(x,y)]
    num = 1
    en = 1
    while en < k:
        #print(perimeter)
        bestpt = None
        bestct = 6
        for pt in perimeter:
            if pt[0] == 0 or pt[0] == m-1 or pt[1] == 0 or pt[1] == n-1:
                if len([1
                        for dx,dy in [(1,0),(-1,0),(0,1),(0,-1)]
                        if valid((pt[0]+dx,pt[1]+dy)) and \
                            not board[pt[1]+dy][pt[0]+dx]]) > 0:
                    ct = 5
                else:
                    continue
            else:
                ct = len([1
                          for dx,dy in [(1,0),(-1,0),(0,1),(0,-1)]
                          if not board[pt[1]+dy][pt[0]+dx]])
            #print(pt,ct)
            if ct < bestct:
                bestpt = pt
                bestct = ct
        #print(bestct,bestpt)
        if bestct == 0 or bestct == 6:
            break
        for dx,dy in [(1,0),(-1,0),(0,1),(0,-1)]:
            newpt = (bestpt[0]+dx,bestpt[1]+dy)
            if not valid(newpt): continue
            if not board[newpt[1]][newpt[0]]:
                board[newpt[1]][newpt[0]] = True
                perimeter.append(newpt)
                en += 1
                if bestct > 1:
                    num += 1
                else:
                    perimeter.remove(bestpt)
                break
    if en >= k:
        print("Case #%d: %d"%(testnum,num))
    else:
        raise AssertionError()

for i in range(int(input())): solve(i+1)
