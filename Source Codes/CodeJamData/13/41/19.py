""" imports """
import glob, pprint, pickle, os, time, sys
from copy import copy
from numpy import array, sin, cos
""" global variables """
""" classes """
""" functions """
def solve(numstops, question):
    return (actualCost(numstops,question) - efficientCost(numstops,question)) % 1000002013
def actualCost(numstops, question):
    cost = 0
    for start,end,passengers in question:
        distance = end-start
        cost += passengers*(distance*(numstops*2-distance+1)/2)
    return cost
def efficientCost(numstops, question):
    '''step 1: create efficient notation'''
    enters = [0]*len(question)
    exits = [0]*len(question)
    for index,(start,end,passengers) in enumerate(question):
        enters[index] = (start,passengers)
        exits[index] = (end,passengers)
    
    enters.sort()
    exits.sort()
    '''step 2: simplify'''
    pass
    
    
    '''step 3: calculate'''
    cost = 0
    tickets = []
    while enters or exits:
        if enters and (enters[0][0] <= exits[0][0]):
            tickets.append(enters[0])
            del enters[0]
        else:
            '''They now use the most expensive tickets if they leave'''
            leavers = exits[0][1]
            while leavers > 0:
                '''most expensive tickets are at the end'''
                if leavers >= tickets[-1][1]:
                    leavers -= tickets[-1][1]
                    '''calculate the cost'''
                    
                    distance = exits[0][0]-tickets[-1][0]
                    cost += tickets[-1][1]*(distance*(numstops*2-distance+1)/2)
                    del tickets[-1]
                else:
                    tickets[-1] = (tickets[-1][0],tickets[-1][1]-leavers)
                    '''calculate the cost'''
                    distance = exits[0][0]-tickets[-1][0]
                    cost += leavers*(distance*(numstops*2-distance+1)/2)
                    leavers = 0
            del exits[0]
    return cost
output = ""
TIC = time.time()
with open(sys.argv[1] if len(sys.argv) > 1 else "default.in") as f:
    def read_ints():
        return [int(x) for x in f.readline().strip().split(' ')]
    (numquestions,) = read_ints()
    for questionindex in xrange(numquestions):
        ### parse input ###
        numstops, numlines = read_ints()
        question = []
        for i in xrange(numlines):
            question.append( read_ints() )
        ### calculate answer ###
        answer = solve(numstops,question)
        ### output ###
        #print "Calculating case #{}...".format(questionindex+1)
        answer_str = "Case #{}: {}".format(questionindex+1, answer)
        output += answer_str + '\n'
        print answer_str
ofile = open('output', 'w').write(output)
TOC = time.time()
#print "done in {} s".format(TOC-TIC)
