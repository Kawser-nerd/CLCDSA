#!/usr/bin/env python
#coding=utf-8

problem = 'c'
input_file_name = problem + ".in"
output_file_name = problem + ".out"
test_data = """3
3 4
1 2 3 4
2 3 4 6
6 5 4 3
3 3
5 5 5
4 4 6
4 5 4
5 2
1 1
2 2
5 4
4 4
4 1
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
        nn, kk = map(lambda x: int(x), input[iLine].strip().split())
        iLine += 1
        stk = []
        for i in range(nn):
            stk.append(map(lambda x: int(x), input[iLine].strip().split()))
            iLine += 1
        print stk

        ##########################
        # Solve the case here
        intsc = []
        for i in range(nn):
            intsc.append([False]*nn)
        for i in range(nn-1):
            for j in range(i+1,nn):
                for k in range(kk-1):
                    if 0 >= (stk[i][k] - stk[j][k])*(stk[i][k+1] - stk[j][k+1]):
                        intsc[i][j] = True
                        intsc[j][i] = True
                        break
        
        for i in intsc:
            print i
        
        result = 1
        ss = []
        for i in range(nn):
            ns = [[i]]
            for s in ss:
                flag = True
                for j in s:
                    if intsc[i][j] == False:
                        flag = False
                        break
                if flag:
                    ts = []
                    ts[:] = s[:]
                    ts.append(i)
                    if len(ts) > result:
                        result = len(ts)
                    ns.append(ts)
            ss.extend(ns)
        
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
    
