# -*- coding: utf-8 -*-
"""
Created on Sun May 11 12:55:27 2014

@author: eidanch
"""


def get_line():
    return raw_input().strip()

formatIntegerList = lambda s: list(map(int,s.split(' ')))

def standard_input():
    T = int(get_line())
    for i in range(T):
        lst = formatIntegerList(get_line())
        yield (i+1,(lst[0],lst[1],lst[2]))

def enclosed(N,M,K,grid):
    for i in range(N):
        if grid[i][0] != 'k':
            grid[i][0] = 'b'
        if grid[i][M-1] != 'k':
            grid[i][M-1] = 'b'
    for j in range(M):
        if grid[0][j] != 'k':
            grid[0][j] = 'b'
        if grid[N-1][j] != 'k':
            grid[N-1][j] = 'b'
    q = list()
    for i in range(N):
        for j in range(M):
            if grid[i][j] == 'b':
                q.append((i,j))
    while len(q) > 0:
        (i,j) = q.pop()
        if valid(N,M,i,j):
            if grid[i][j] == 'b':
                grid[i][j] == 'c'
                q.append((i+1,j))
                q.append((i,j+1))
                q.append((i-1,j))
                q.append((i,j-1))
            elif grid[i][j] == 'k':
                return False
        return True

def valid(N,M,i,j):
    return i >= 0 and j >= 0 and i < N and j < M      
       
def surrounded(N,M,grid,i,j):
    return (valid(N,M,i+1,j) and grid[i+1][j] != ' ') \
        and (valid(N,M,i,j+1) and grid[i][j+1] != ' ') \
        and (valid(N,M,i-1,j) and grid[i-1][j] != ' ') \
        and (valid(N,M,i,j-1) and grid[i][j-1] != ' ')

def handle_case(case):
    N,M,K = case
    inds = [(i,j) for i in range(N) for j in range(M)]
    best = K
    for subset in subsets(inds, K):
        grid = [M*[' '] for i in range(N)]
        for i,j in subset:
            grid[i][j] = 'a'
        for i,j in subset:
            if not surrounded(N,M,grid,i,j):
                grid[i][j] = 'b'
        p = len([(i,j) for (i,j) in subset if grid[i][j] == 'b'])
        if enclosed(N,M,K,grid):
            best = min(best,p)
    return str(best)


def subset_from_bits(lst, vector):
    return [lst[i] for i in xrange(len(lst)) if (1 << i) & vector]

def _nextvector(v):
    t = (v | (v - 1)) + 1;
    return t | ((((t & -t) / (v & -v)) >> 1) - 1)

def subsets(iterable, size=None):
    lst = list(iterable)
    if size:
        vector = (1 << size) - 1
        nextvector =  _nextvector
    else:
        vector = 0
        nextvector = lambda x: x + 1
    while vector < (1 << len(lst)):
        yield subset_from_bits(lst, vector)
        vector = nextvector(vector)

        
def main():
    for i,case in standard_input():
        print "Case #%d: %s" %(i,handle_case(case))        

if __name__ == '__main__':
    main()
    