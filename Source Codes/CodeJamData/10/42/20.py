#!/usr/bin/python

import sys
import os

def line():
    return sys.stdin.readline()[:-1]

def readList():
    return map(eval,line().split())

if __name__ == '__main__':
    numberOfCases = eval(line())
    for caseNumber in range(numberOfCases):
        P = eval(line())
        prices = dict()
        constraints = readList()
        objective = []
        for r in range(P):
            thisRound = sys.stdin.readline().split()
            objective.extend([thisRound[match] + " x_" + str(r) + "_" + str(match) for match in range(len(thisRound))])

        # I call the GNU Linear Programming Kit stand-alone solver glpsol

        objective = "minimize " + '+'.join(objective)

        consts = "st\n"
        consts +=  '\n'.join([' + '.join(["x_" + str(r) + "_" + str(team/2**(r+1)) for r in range(P)]) + " >= " + str(P-constraints[team]) for team in range(2**P)])

        bought = set()

        binary = "binary\n"
        binary += '\n'.join(["x_" + str(r) + "_" + str(match)  for r in range(P) for match in range((2**(P-r)))])
        
        glpinput = open("input.lp",'w')
        print >>glpinput,objective
        print >>glpinput,consts
        print >>glpinput,binary
        print >>glpinput,"end"
        glpinput.close()
        os.system("glpsol --cpxlp --intopt input.lp > output.lp")
        outputFile = open('output.lp')
        output = outputFile.readlines()
        outputFile.close()
        for i in range(len(output)):
            if "INTEGER OPTIMAL SOLUTION FOUND" in output[i]:
                solution = output[i-1]
                if "Objective value" in solution:
                    solution = solution.split()[-1]
                else:
                    solution = str(int(float(solution.split()[4]))).replace("L","")
                break
        
        print "Case #" + str(caseNumber+1) + ": " + solution
