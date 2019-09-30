import sys
import math
import decimal
import copy
import re


class Solver:
    def __init__(self, input, output):
        size = int(input.readline())
        print (str(size))
        for index in range(size):
            case = BCase(input)
            result = case.solve()
            print ("Case #" + str(index + 1) + ": " + str(result))
            output.write("Case #" + str(index + 1) + ": " + str(result) + "\n")
            
class BCase:
    def __init__(self, file):
        self.amountOfPoints = int(file.readline())
        self.points = []
        for i in range(self.amountOfPoints):
            self.points.append([int(part) for part in file.readline().strip().split()])
    def solve(self):
        current = [0,0,0,0,0,0]
        for i in self.points:
            for j in range(len(i)):
                current[j] = current[j] + i[j];
        for j in range(len(i)):
            current[j]/=self.amountOfPoints
        if ((current[3]*current[3] + current[4]*current[4] + current[5]*current[5] )> 0):
            t = -(2*current[0]*current[3] + 2*current[1]*current[4] + 2*current[2]*current[5])/(2*(current[3]*current[3] + current[4]*current[4] + current[5]*current[5]))
        else:
            t = 0;
        if (t < 0):
            t = 0;
        d = math.sqrt(math.pow(current[0]+current[3]*t, 2) + math.pow(current[1]+current[4]*t, 2) + math.pow(current[2]+current[5]*t, 2))
        return str(d) + " " + str(t);
class ACase:
    def __init__(self, file):
        self.letters= input.readline().strip();
    def solve(self):
        solution = 0
        nextIndex = 1
        indexedLetters = {}
        for letter in self.letters:
            if (letter in indexedLetters):
                continue
            else:
                indexedLetters[letter] = nextIndex
                if (nextIndex == 1):
                    nextIndex = 0
                else: 
                    if (nextIndex == 0):
                        nextIndex = 2
                    else:
                        nextIndex+=1
        if (nextIndex == 0):
            nextIndex = 2
        for letter in self.letters:
            solution = solution * nextIndex + indexedLetters[letter]
        return str(solution)         
        
type = "B"
if (0):
    size = "-small-attempt0" 
else: 
    size = "-large"
filename = "..\\" + type + size + ".in"
outputname = "result.txt"
input = open(filename, 'r')
output = open(outputname, 'w')
try:
    Solver(input, output)
except:
    print("Unexpected error:", sys.exc_info()[0])
    raise
finally:
    input.close()
    output.close()

