#!/usr/bin/python
#b.py
#Author: James Damore
#Created on: May 06, 2011
#Time-stamp: <2011-05-06 19:28:31>
#~/python/codeJam/b.py

import math
import string
import numpy as nm
import sys
import codejam as cj

def make_com(command, coms):
    if len(command) > 1 and (command[-1], command[-2]) in coms:
        command[-2] = coms[(command[-1], command[-2])]
        command.pop()
        make_com(command, coms)
    return command

def run_invoke(invoke, coms, killers):
    command = []
    for i in invoke:
        command.append(i)
        command = make_com(command, coms)
        for k in command[0:-1]:
            if (k, command[-1]) in killers:
                command = []
                break
    return command
    
def read_input():
    strings = raw_input().split()
    numCom = int(strings[0])
    com = [i for i in strings[1:numCom+1]]
    numKill = int(strings[1 + numCom])
    kill = [i for i in strings[2 + numCom:2 + numCom + numKill]]
    invoke = [letter for letter in strings[-1]]
    coms = {}
    killers = set()
    for c in com:
        coms[(c[0], c[1])] = c[2]
        coms[(c[1], c[0])] = c[2]
    for k in kill:
        killers.add((k[0], k[1]))
        killers.add((k[1], k[0]))

    #print killers
    #print coms
    
    command = run_invoke(invoke, coms, killers)
    return '[' + ', '.join(command) + ']'


numCases=input()
for i in range(1, numCases+1):
    #read_input()
    output = read_input()
    print "Case #%d:" % i, output
