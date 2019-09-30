#!/usr/bin/env python
#coding=utf-8

problem = 'a'
input_file_name = problem + ".in"
output_file_name = problem + ".out"
test_data = """
"""
test_data = None

def process(input):
    output = []
    iLine = 0
    N = int(input[iLine].strip())
    iLine += 1
    for case in range(1, N + 1):
        print "Case %d"%case
        
        ##########################
        # Get source data here
        nn = int(input[iLine].strip())
        iLine += 1
        for i in range(nn):
            input[iLine].strip()
            iLine += 1
        

        ##########################
        # Solve the case here
        result = 0
        output.append(result)
        ##########################
        
        
    return output

def main():
    input = None
    if test_data is None:
        ifile = open(input_file_name)
        input = ifile.readlines()
        ifile.close()
    else:
        input = test_data.split('\n')
        
    output = process(input)
    
    if test_data is None:
        ofile = open(output_file_name, 'w')
        for i in range(len(output)):
            print >> ofile, "Case #%d:"%(i + 1), output[i]
        ofile.close()
    for i in range(len(output)):
        print "Case #%d:"%(i + 1), output[i]
        
    return len(output)
        
if __name__ == "__main__":
    import time
    start = time.time()
    N = main()
    print "Done in %f seconds"%(time.time() - start)
    print "Average %f milliseconds"%((time.time() - start) * 1000 / N)
    
