#!/usr/bin/env python

import re
import sys

class Memoize:
    def __init__(self,function):
        self._cache = {}
        self._callable = function
            
    def __call__(self, *args, **kwds):
        cache = self._cache
        key = self._getKey(*args,**kwds)
        try: return cache[key]
        except KeyError:
            cachedValue = cache[key] = self._callable(*args,**kwds)
            return cachedValue
    
    def _getKey(self,*args,**kwds):
        return kwds and (args, ImmutableDict(kwds)) or args    

def find_directions(the_map):
    H, W = len(the_map), len(the_map[0])
    dirs = [(0,-1), (-1,0), (1,0), (0,1)]
    dir_map = []
    for y in range(H):
        row = []
        for x in range(W):
            #print "ON SQUARE", x, y
            best_val, best_dir = the_map[y][x], None
            for d in dirs:
                x1 = x + d[0]
                y1 = y + d[1]
                if 0<=x1<W and 0<=y1<H:
                    #print "checking", x1, y1
                    v = the_map[y1][x1]
                    if v < best_val:
                        best_val, best_dir = v, (x1,y1)
            #print "best is", best_dir
            row.append(best_dir)
        dir_map.append(row)
    return dir_map

def do_trial(the_map):
    directions = find_directions(the_map)
    basin = [[None for v in t] for t in directions]
    for y in range(H):
        for x in range(W):
            if directions[y][x] is None:
                basin[y][x] = frozenset([(x,y)])
    #for r in basin: print r
    for y in range(H):
        for x in range(W):
            if basin[y][x] is None:
                path = set([(x,y)])
                x1,y1=x,y
                while 1:
                    p = directions[y1][x1]
                    if p is None:
                        break
                    path.add(p)
                    x1,y1 = p
                # unwind path into the basin set
                #print "path=", path
                #print x1, y1
                new_set = frozenset(basin[y1][x1].union(path))
                for p in new_set:
                    basin[p[1]][p[0]] = new_set
    #for r in basin: print r
    basin_list = [[None for i in range(W)] for j in range(H)]
    lookup = {}
    next = 'a'
    for y in range(H):
        for x in range(W):
            fs = basin[y][x]
            if not lookup.has_key(fs):
                lookup[fs] = next
                next = chr(ord(next)+1)
                #print "NEXT=>", next
                #print "x,y=>", x,y
                #print "lookup=>", lookup
            basin_list[y][x] = lookup[fs]
    return basin_list

f = sys.stdin
T = int(f.readline())
for i in range(T):
    the_map = []
    H, W = [int(x) for x in f.readline().split()]
    for j in range(H):
        the_map.append([int(x) for x in f.readline().split()])
    basin = do_trial(the_map)
    print "Case #%d:" % (i+1)
    for row in basin:
        print " ".join(row)
