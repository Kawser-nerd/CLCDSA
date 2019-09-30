#!/usr/bin/env python
#coding=utf-8

problem = 'aa'
input_file_name = problem + ".in"
output_file_name = problem + ".out"
test_data = """3
2
10
11
3
001
100
010
4
1110
1100
1100
1000
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
        N = []
        for i in range(nn):
            ss = input[iLine].strip()
            N.append(-1)
            for i in range(nn-1, -1, -1):
                if ss[i] == '1':
                    N[-1] = i
                    break
            iLine += 1
#        print N

        ##########################
        # Solve the case here
        result = 0
        for i in range(nn-1):
            if N[i] <= i:
                continue
            ii = -1
            for j in range(i+1, nn):
#                print nn, j, len(N)
                if N[j] <= i:
                    ii = j
                    break
            for k in range(ii, i, -1):
                N[k], N[k-1] = N[k-1], N[k]
                result += 1
                    
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
    
