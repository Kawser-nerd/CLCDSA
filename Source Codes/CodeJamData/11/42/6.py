

def findsize(cells, row, col, size):
    #upper-left
    centerr = size-1
    centerc = size-1
    rdiff = 0
    cdiff = 0
    for r in range(size):
        for c in range(size):
            if ((r == 0 and (c == 0 or c == size-1)) or (r == size-1 and (c == 0 or c == size-1))):
                pass
            else:
                #print(str(r)+','+str(c)+","+str(cells[row+r][col+c]*(2*r-centerr))+','+str(cells[row+r][col+c]*(2*c-centerc)))
                rdiff += cells[row+r][col+c]*(2*r-centerr)
                cdiff += cells[row+r][col+c]*(2*c-centerc)
    #print(str(size)+" "+str(row)+" "+str(col)+" "+str(rdiff)+" "+str(cdiff))
    if (rdiff == 0 and cdiff == 0):
        return True
    else:
        return False


with open('input.in', 'r') as fin:
    with open('output.txt', 'w') as fout:
        numcases = int(fin.readline())
        for casenum in range(1, numcases+1):
            info = [int(i) for i in fin.readline().split()]
            rows = []
            for i in range(info[0]):
                line = fin.readline()
                rows.append([int(line[i]) for i in range(info[1])])

            solnstr = "IMPOSSIBLE"
            solnfd = False

            for size in range(min((info[0], info[1])), 2, -1):
                for r in range(info[0]+1-size):
                    for c in range(info[0]+1-size):
                        if (findsize(rows, r, c, size)):
                            solnstr = str(size)
                            solnfd = True
                            break
                    if solnfd:
                        break
                if solnfd:
                    break













            fout.write("Case #"+str(casenum)+": "+solnstr+'\n')
