#!/usr/bin/env python

from collections import deque

def read_case(read):
    [R] = read_int_line(read)
    sq = []
    for x in xrange(R):
        sq.append(read_int_line(read))
    return R, sq

def solve_small(data):
    R, sq = data
    INF = 10000000
    
    cells = []
    for x in xrange(110):
        cells.append([False]*110)
        
    cnt = 0
    
    for (x1, y1, x2, y2) in sq:
        if (x1>x2):
            t = x1
            x1 = x2
            x2 = t
            
        if (y1>y2):
            t = y1
            y1 = y2
            y2 = t
            
        for x in xrange(x1, x2+1):
            for y in xrange(y1, y2+1):
                cells[x][y] = True
    
    def emp(cells):
        return not any([any(row) for row in cells])
        
    cnt = 0
    while (not emp(cells)):
        
        cnt += 1
        for x in xrange(len(cells)-1, 0, -1):
            for y in xrange(len(cells[x])-1, 0, -1):
                if (cells[x-1][y]==True and cells[x][y-1]==True):
                    cells[x][y] = True
                    
                if (cells[x-1][y]==False and cells[x][y-1]==False):
                    cells[x][y] = False

    return cnt

def solve_case(data):
    
    return solve_small(data)
    R, sq = data
    INF = 10000000
    cells = {}
    
    for (x1, y1, x2, y2) in sq:
        if (x1>x2):
            t = x1
            x1 = x2
            x2 = t
            
        if (y1>y2):
            t = y1
            y1 = y2
            y2 = t
            
        for x in xrange(x1, x2+1):
            for y in xrange(y1, y2+1):
                cells[(x, y)] = 0
                
    q = deque()
    
    for (x,y) in cells.keys():
        if (x+1, y) not in cells \
                and (x, y-1) not in cells\
                and (x+1, y-1) not in cells:
            cells[(x,y)] = 1
            q.append( (x,y) )
            #print (x,y)
    
    while len(q) > 0:
        (x,y) = q.popleft()
        leftright = False
        
        if (x-1, y) in cells and cells[(x-1, y)] < cells[(x,y)]+1:
            cells[(x-1, y)] = cells[(x,y)] + 1
            q.append((x-1, y))
            #print (x,y), 1
            leftright = True
            
        if (x, y+1) in cells and cells[(x, y+1)] < cells[(x,y)]+1:
            cells[(x, y+1)] = cells[(x,y)] + 1
            q.append((x, y+1))
            #print (x,y), 2
            leftright = True
            
        if not leftright and (x-1, y+1) in cells and cells[(x-1, y+1)] < cells[(x,y)]+1:
            cells[(x-1, y+1)] = cells[(x,y)] + 1
            q.append((x-1, y+1))
            #print (x,y), 3
        
    m = 0
    for key in cells.keys():
        if (m < cells[key]):
            m = cells[key]
    
    return m

def main():
    solve_n_cases(solve_case, read_case)

##### PROBLEM VARIABLES ######

INFILENAME = 'C-small-attempt1.in'
OUTFILENAME = 'output.out'

##### PROBLEM TEMPLATE ######

from time import time
from multiprocessing import Pool
   
def init_io():
    read = open(INFILENAME, 'rt')
    write = open(OUTFILENAME, 'wt')
    return (read, write)

def deinit_io(read, write):
    read.close()
    write.close()
    
def read_token_line(read, tokenparsefunction):
    return [tokenparsefunction(x)
                for x in read.readline().split()]
    
def read_int_line(read):
    return read_token_line(read, int)
    
def output_case_sharp(write, casenum, result):
    write.write( 'Case #{0}: {1}\n'.format(casenum, result) )

def solve_n_cases(solve_function, read_function, output_function = output_case_sharp):
    read, write = init_io()
    
    cases_num = int(read.readline())
    current_case = 1
    cases_data = []
    p = Pool()
    
    started = time()
    
    while (cases_num>0):
        cases_data.append( read_function(read) )        
        cases_num -= 1
        
    results = p.map(solve_function, cases_data)
    
    for result in results:
        output_function(write, current_case, result)
        current_case += 1
        
    finished = time()
    
    print 'Finished in {0:.2} sec.'.format(finished-started)
    
    deinit_io(read, write)

if __name__ == "__main__":
    main()