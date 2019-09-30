# -*- coding: utf-8 -*-
"""
@author: jmzhao
GCJ 2016 Round 2
"""

import sys
import itertools
import numpy as np

class IO :
    def get(reader=str) :
        return reader(input().strip())
    def gets(reader=str, delim=None) :
        return [reader(x) for x in input().strip().split(delim)]
    def tostr(raw, writer=str, delim=' ') :
        return delim.join(writer(x) for x in raw)

def prework(argv):
    '''do something according to argv,
    return a message describing what have been done.'''
    pass

r = None; c = None;

def on_board(p) :
#    printerr(p)
    x, y = p
    return x>=0 and x<r and y>=0 and y<c

def _conv(i) :
    i -= 1
    if i < c :
        return (-1, i), (1, 0)
    elif i < c + r :
        return (i-c, c), (0, -1)
    elif i < c + r + c :
        return (r, c+c+r-i-1), (-1, 0)
    elif i < c + r + c + r :
        return (c+c+r+r-i-1, -1), (0, 1)
def conv(i) :
    p, d = _conv(i)
    return np.array(p), np.array(d)

def is_connected(maze, src, tar) :
    p, d = conv(src)
    t, _ = conv(tar)
#    printerr(p, d)
    
    p = p + d
    while True :
        if np.all(p == t) :
            return True
        if not on_board(p) :
            return False
        x, y = d
        d = np.array([y, x])
        x, y = p
        if maze[x][y] == '/' : 
            d = -d
        p = p + d

def once():
    '''to cope once'''
    global r, c
    
    r, c = IO.gets(int)
    p = IO.gets(int)
    
    love = dict()
    for i in range(0, len(p), 2) :
        love[p[i]] = p[i+1]
        
    for flat_maze in itertools.product('/\\', repeat=r*c) :
        maze = list(zip(*[iter(flat_maze)]*c))
#        printerr(maze)
        if all(is_connected(maze, src, tar) for src, tar in love.items()) :
            return maze
    return None

def show(ans) :
    return '\n' + (
        'IMPOSSIBLE' if ans is None else '\n'.join(''.join(row) for row in ans)) #IO.tostr(ans, writer=str, delim=' ')
    
def printerr(*v):
    print(*v, file=sys.stderr)

def main():
    TT = int(input())
    for tt in range(1,TT+1):
        printerr("coping Case %d.."%(tt))
        ans = once()
        print("Case #%d: %s"%(tt, show(ans)))

if __name__ == '__main__' :
    msg = prework(sys.argv)
    print("prework done with", msg, file=sys.stderr)
    main()
