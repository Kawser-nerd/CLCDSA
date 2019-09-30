#!/usr/bin/python3
__author__ = 'Tianren Liu'

import sys
import numpy as np

if __name__ == "__main__":
    T = int(sys.stdin.readline())
    for t in range(T):
        print("Case #{}:".format(t+1))
        R,C = map(int, sys.stdin.readline().split())
        N = 2*(R+C)
        L = [int(i) for i in sys.stdin.readline().split()]
        L = np.array(L)
        L = L.reshape(-1,2)
        L = [(b,a) if (b-a)%N < (a-b)%N else (a,b) for a,b in L]
        L.sort(key=lambda x: (x[0]-x[1])%N)

        impossible = False
        for a,b in L:
            for c,d in L:
                if a != c:
                    if (c-a)%N < (b-a)%N < (d-a)%N or (c-a)%N > (b-a)%N > (d-a)%N:
                        impossible = True
        if impossible:
            print('IMPOSSIBLE')
            continue
        # continue
        maze = [list('?'*C) for _ in range(R)]
        for s,t in L:
            if s <= C:
                y = 0
                x = s-1
                d = 'v'
            elif s <= C+R:
                y = s-C-1
                x = C-1
                d = '<'
            elif s <= C+R+C:
                y = R-1
                x = C+C+R-s
                d = '^'
            else:
                y = C+R+C+R-s
                x = 0
                d = '>'
            while 0 <= x < C and 0 <= y < R:
                if maze[y][x] == '?':
                    if d == '<' or d == '>':
                        maze[y][x] = '\\'
                    else:
                        maze[y][x] = '/'
                if maze[y][x] == '\\':
                    d = {'<':'^','>':'v','^':'<','v':'>'}[d]
                else:
                    d = {'<':'v','>':'^','^':'>','v':'<'}[d]
                if d == '<':
                    x -= 1
                elif d == '>':
                    x += 1
                elif d == '^':
                    y -= 1
                else:
                    y += 1
            if y < 0:
                tr = x+1
            elif x >= C:
                tr = C+y+1
            elif y >= R:
                tr = C+R+(C-x)
            else:
                tr = C+R+C+(R-y)
            if tr != t:
                print('IMPOSSIBLE')
                break
            # print ('add',s,t,R,C)
            # for m in maze:
            #     print(''.join(m))
        else:
            for m in maze:
                print(''.join(m).replace('?','/'))
