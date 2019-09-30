"""
Jonathan Simowitz

Google Code Jam 2011
Round 1C Question 1

"""

import os

"""
Funciton responsible for applying the algorithm
on the test data and returning the output
"""
def process(data, rf):
    data = data.split(" ")
    rows = int(data[0])
    cols = int(data[1])

    picture = []
    for r in range(rows):
        data = rf.readline()
        data = data.replace('#','0')
        data = data.strip()
        picture.append(list(data))

    outstr = ""
    for r in range(rows):
        outrow = ""
        for c in range(cols):
            if (picture[r][c] == '0'):
                try:
                    if ((picture[r][c+1] == '0') and
                        (picture[r+1][c] == '0') and
                        (picture[r+1][c+1] == '0')):
                        picture[r][c] = "/"
                        picture[r][c+1] = "\\"
                        picture[r+1][c] = "\\"
                        picture[r+1][c+1] = "/"
                    else:
                        return "Impossible\n"
                except:
                    return "Impossible\n"
            outrow += picture[r][c]
        outstr += outrow + "\n"

    return outstr
            

"""
Main function initializes files, iterates through
data, writes output, and closes the files.
"""
def main():
    #Open the input file
    rf = open(os.path.join(os.getcwd(), "A-large.in"), "r")
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
                wf.write("Case #" + str(test_num) + ":\n" + process(line, rf))
                #increment the test case number
                test_num += 1

main()
