#!/usr/bin/env python
# -*- coding: utf-8 -*-
import os
import sys

fin = open('squaret.in','r')
T = int(fin.readline()[:-1])
for tttt in range(T):
    W,Q = [int(l) for l in fin.readline().split()]
    data = [list(fin.readline()[:-1]) for w in range(W)]
    goal = [int(l) for l in fin.readline().split()]
    result = ["" for g in goal]

    table = [[ [] for j in range(W)] for i in range(W)]

    for i in range(W):
        for j in range(W):
            if '0' <= data[i][j] <= '9':
                table[i][j] = [[data[i][j], int(data[i][j])]]

    def check():
        for x in range(len(goal)):
            if result[x] == "":
                l = []
                for i in range(W):
                    for j in range(W):
                        l.extend( [t[0]  for t in table[i][j] if t[1] == goal[x]] )
                if len(l) > 0:
                    result[x] = min(l)

    while True:
#        print "DATA"
#        print data
#        print "TABLE"
#        print table
        check()
        if len([r for r in result if r == ""]) == 0:
            print "Case #"+str(tttt+1)+":"
            for t in result:
                print t
            break

        new = [[ [] for j in range(W)] for i in range(W)]
        for i in range(W):
            for j in range(W):
                if '0' <= data[i][j] <= '9':
                    for t in table[i][j]:
                        for x,y in [[-1,0],[1,0],[0,-1],[0,1]]:
                            for xx,yy in [[-1,0],[1,0],[0,-1],[0,1]]:
                                if 0<=i+x<W and 0<=j+y<W and 0<=i+x+xx<W and 0<=j+y+yy<W:
                                    k = eval(str(t[1])+data[i+x][j+y]+data[i+x+xx][j+y+yy])
                                    if -50<k<100:
                                        s = t[0]+data[i+x][j+y]+data[i+x+xx][j+y+yy]
                                        bo = True
                                        for n in new[i+x+xx][j+y+yy]:
                                            if n[1] == k:
                                                bo = False
                                                if n[0] > s:
                                                    n[0] = s
                                        if bo:
                                            new[i+x+xx][j+y+yy].append( [s,k] )
        table = new 
