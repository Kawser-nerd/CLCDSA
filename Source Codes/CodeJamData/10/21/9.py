#!/usr/bin/env python
# coding=utf-8
from scanf import *
opers = 0
class Node:
    def __init__(self):
        self.children = {}
    def addPath(self,path):
        if len(path) == 0:return
        if not path[0] in self.children:
            global opers
            opers += 1
            self.children[path[0]] = Node()
        self.children[path[0]].addPath(path[1:])

def solveCase(cas):
    global opers
    n,m = scanf("%d%d")
    root = Node()
    for i in range(n):
        root.addPath(scanf("%s")[0].split("/")[1:])
    opers = 0
    for i in range(m):
        root.addPath(scanf("%s")[0].split("/")[1:])
    print("Case #"+str(cas)+": "+str(opers))

if __name__ == "__main__":
    tests = scanf("%d")[0]
    for i in range(tests):
        solveCase(i+1)
