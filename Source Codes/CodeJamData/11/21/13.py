#!/usr/bin/env python
import sys

t = int(sys.stdin.readline())
mat = []
win_memo = []
owin_memo = []
    

def win(i,n,ignore=-1):
    if win_memo[i] != -1:
        return win_memo[i]
    win = 0.
    tot = 0.
    for j in range(n):
        if j == ignore:
            continue
        if mat[i][j] == 1:
            win += 1
            tot += 1
        elif mat[i][j] == 0:
            tot += 1
    if win == 0:
        win_memo[i] = 0.
        return 0.
    else:
        win_memo[i] = win/tot
        return win/tot

def owin(i,n,ignore=-1):
    op_tot = 0.
    op_win = 0.
    for k in range(n):
        if mat[i][k] != -1:
            op_win += win(k,n,i)
            op_tot += 1
    return op_win/op_tot

def oowin(i,n):
    op_tot = 0.
    op_win = 0.
    for k in range(n):
        if mat[i][k] != -1:
            op_win += owin(k,n)
            op_tot += 1
    return op_win/op_tot

def run():
    global mat
    n = int(sys.stdin.readline())
    mat = [[0]*n for x in xrange(n)]
    for i in range(n):
        line = sys.stdin.readline()
        for j in range(n):
            if line[j] == '0':
                mat[i][j] = 0
            elif line[j] == '1':
                mat[i][j] = 1
            else:
                mat[i][j] = -1

    #for i in range(n):
    #    print win(i,n), owin(i,n), oowin(i,n)
    ret = [0]*n
    for i in range(n):
        ret[i] = 0.25*win(i,n)
    for i in range(n):
        ret[i] += 0.5*owin(i,n)
    for i in range(n):
        ret[i] += 0.25*oowin(i,n)

    return ret


for test in range(1,t+1):
    rpi = run()
    print "Case #%d:" % test
    for r in rpi:
        print "%f" % r
