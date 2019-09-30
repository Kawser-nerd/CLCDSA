"""
Jonathan Simowitz

Google Code Jam 2011
Round 1C Question 2
Space Emergency
"""

import os

"""
Funciton responsible for applying the algorithm
on the test data and returning the output
"""
def process(data):
    data = data.split(" ")
    L = int(data[0]) #number of speed boosters
    t = int(data[1]) #t hours to build speed booster
    N = int(data[2]) #Star N is the goal
    C = int(data[3]) 

    C_vals = [] #distances to each star
    for i in range(C):
        C_vals.append(int(data[4+i]))

    stars = []
    loc = 0
    index = 0
    distances = []
    times = []

    for star in range(N):
        loc += C_vals[index]
        stars.append(loc)
        distances.append(C_vals[index])
        times.append(float(loc) / 0.5)

        index += 1
        if (index == C):
            index = 0
    
    #time to reach end without any speed booster
    max_time = float(loc) / 0.5

    #distanct traveled by the time the first speed boster is built
    dbuild = float(t) * 0.5

    #remove stars that cannot build speed boosters
    index = 0
    
    while index < len(stars):
        if (stars[index] < dbuild):
            distances[index] = -1
        else:
            #this star might build a partial booster
            if (index == 0):
                distances[index] -= dbuild
            else:
                dbuild -= stars[index-1]
                distances[index] -= dbuild
            break
        index += 1    
        
    while(index < N and stars[index] < dbuild):
        distances[index] = -1
        index += 1

    distances.sort()
    distances.reverse()

    max_sum = 0
    if (L < len(distances)):
        for i in range(L):
            if (distances[i] == -1):
                break
            max_sum += distances[i]
    else:
        for distance in distances:
            if (distance == -1):
                break
            max_sum += distance
        
    max_time -= max_sum

    return str(int(max_time))

"""
Main function initializes files, iterates through
data, writes output, and closes the files.
"""
def main():
    #Open the input file
    rf = open(os.path.join(os.getcwd(), "B-large.in"), "r")
    #Open the output file
    wf = open(os.path.join(os.getcwd(), "output.txt"), "w")

    heading = True
    test_num = 1

    #Iterate through the input file
    while True:
        #read input one line at a time
        line = rf.readline()
        line = line.strip()

        if not line:
            #end of file

            #close input file
            rf.close()
            #close output file
            wf.close()
            break
        else:
            #process the line

            if (heading):
                heading = False
                NUM_TEST_CASES = int(line)
            else:
                #print the output
                wf.write("Case #" + str(test_num) + ": " + process(line) + "\n")
                #increment the test case number
                test_num += 1

main()
