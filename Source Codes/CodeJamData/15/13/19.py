'''
CodeJam Practice 
Created on 2012-12-20

@author: festony
'''

from cj_lib import *
from properties import *

import math
import fractions


#curr_file_name = 'C-large'
curr_file_name = 'C-small-attempt0'
#curr_file_name = 'test'

# map(int, input_lines.pop(0).split(' '))

def input_dividing_func(input_lines):
    total_case = int(input_lines.pop(0))
    case_inputs = []
    for i in range(total_case):
        N = int(input_lines.pop(0))
        t = []
        for i  in range(N):
            t.append(map(int, input_lines.pop(0).split(' ')))
        case_inputs.append(t)
    return case_inputs
    
def process_func(func_input):
    t = map(lambda x:tuple([float(x[0]), float(x[1])]), func_input)
    #print t
    
    def testOnLine(A, B, P):
        r = ((B[0]-A[0])*(P[1]-A[1])-(B[1]-A[1])*(P[0]-A[0]))
        if r > 0:
            return 1
        elif r < 0:
            return -1
        return 0
    
    testonlinecache = {}
    cache = {}
    
    r = []
    for i in range(len(t)):
        subr = len(t) - 1
        for j in range(len(t)):
            if j == i:
                continue
            subsubr = 0
            if cache.has_key((i, j)):
                subsubr = cache[(i, j)]
            else:
                left = []
                right = []
                on = []
                for k in range(len(t)):
                    if k == i or k == j:
                        continue
                    if testonlinecache.has_key((i, j, k)):
                        tr = testonlinecache[(i, j, k)]
                    else:
                        tr = testOnLine(t[i], t[j], t[k])
                        testonlinecache[(i, j, k)] = tr
                        testonlinecache[(j, i, k)] = -1*tr
                    
                    if tr > 0:
                        left.append(k)
                    elif tr < 0:
                        right.append(k)
                    else:
                        on.append(k)
                    subsubr = min(len(left), len(right))
                    cache[(i, j)] = subsubr
                    cache[(j, i)] = subsubr
            
            
            if subsubr < subr:
                subr = subsubr
        r.append(subr)
    str_r = ''
    for sr in r:
        str_r += '\n{}'.format(sr)
    return str_r

run_proc(process_func, input_dividing_func, curr_working_folder, curr_file_name)


