'''
CodeJam Python Lib for Festony, By Festony

Created on 2012-12-12

@author: festony
'''

import time
import inspect
import os.path
import shutil

import properties

from properties import *

__all__ = [ \
           'run_proc', \
           'accumulate', \
           'get_full', \
           'get_perm', \
           'get_comb', \
           'gen_prime', \
           'get_prime_list', \
           ]

print_details = True

def print_detailed_info(info):
    if print_details:
        print info

def check_input(working_folder, file_name, func):
    in_path = working_folder + file_name + '.in'
    out_path = working_folder + file_name + '.out'
    
    r = [in_path, out_path, working_folder]
    
    if file_name.find('test') >= 0:
        return r
    
    full_source_path = inspect.getsourcefile(func)
    source_file_name = full_source_path.split('\\')[-1][:-3]
    first_separator_index = source_file_name.find('_')
    if first_separator_index < 0:
        return r
    in_year_str = source_file_name[:first_separator_index]
    in_year = -1
    try:
        in_year = int(in_year_str)
    except ValueError:
        return r
    if in_year < 2007 or in_year > 2020:
        return r
    source_file_name = source_file_name[first_separator_index+1:]
    first_separator_index = source_file_name.find('_')
    if first_separator_index < 0:
        return r
    in_round = source_file_name[:first_separator_index]
    source_file_name = source_file_name[first_separator_index+1:]
    question = source_file_name[0]
    if len(source_file_name) > 1 and source_file_name[1] != '_':
        return r
    if not question.isalpha() or question != question.upper():
        return r
    moved_in_folder = working_folder + in_year_str + "\\" + in_round + "\\"
    if not os.path.isdir(moved_in_folder):
        os.makedirs(moved_in_folder)
    new_in_path = moved_in_folder + file_name + '.in'
    new_out_path = moved_in_folder + file_name + '.out'
    new_r = [new_in_path, new_out_path, moved_in_folder]
    if os.path.isfile(new_in_path):
        return new_r
    if os.path.isfile(in_path):
        shutil.move(in_path, new_in_path)
        return new_r
    return r

def run_proc(func, input_dividing_func, working_folder=default_working_folder, file_name=default_file_name):
    '''Run the function multiple times for cases.
    
    Process time for each run / all runs are tracked.
    1) need to provide the function to process each case, the function
    should take a list as raw func_input;
    2) an input_dividing_func should be provided to break func_input lines into func_input lists
    for each case.
    '''
    in_path = working_folder + file_name + '.in'
    out_path = working_folder + file_name + '.out'
    in_path, out_path, working_folder = check_input(working_folder, file_name, func)
    inputfile = open(in_path, 'r')
    raw_input_str = inputfile.read()
    inputfile.close()
    input_lines = map(lambda x:x.rstrip('\r\n'), raw_input_str.split('\n'))
    inputs = input_dividing_func(input_lines)
    r = ''
    case_total_num = len(inputs)
    print_detailed_info('{0} cases in total.'.format(case_total_num))
    start_time_overall = time.clock()
    
    for i, func_input in enumerate(inputs):
        case_num = i + 1
        print_detailed_info('Case {0}:'.format(case_num))
        start_time_single_case = time.clock()
        r += 'Case #%d: %s\n' % (case_num, str(func(func_input)))
        print_detailed_info("Process time: %g sec(s)" % \
        (time.clock() - start_time_single_case,))
        print_detailed_info("Overall process time till now: %g sec(s)" % \
        (time.clock() - start_time_overall,))
    
    end_time_overall = time.clock()
    print(r)
    print("Overall process time: %g sec(s)" % \
    (end_time_overall - start_time_overall,))
    outputfile = open(out_path, 'w')
    outputfile.write(r)
    outputfile.close()
    
    if not ('practice' in file_name or 'test' in file_name):
        shutil.copy(inspect.getsourcefile(run_proc), working_folder)
        shutil.copy(inspect.getsourcefile(properties), working_folder)
        shutil.copy(inspect.getsourcefile(func), working_folder)
    
    return r

# commonly used functions

def accumulate(l):
    r = l[:]
    for i in range(1, len(r)):
        r[i] += r[i-1]
    return r

def get_full(k):
    r = []
    k1 = 0
    for i in range(k):
        if r == []:
            for j in range(k):
                r.append([j])
        else:
            l = len(r)
            for j in range(l):
                temp = r.pop(0)
                for j1 in range(k):
                    temp2 = temp + [j1]
                    r.append(temp2)
    return r

def get_perm(k, n):
    if k == 0:
        return []
    r = []
    if k == 1:
        for i in range(n):
            r.append([i])
        return r
    r1 = get_perm(k-1, n)
    r = []
    for p in r1:
        for j in range(max(p)+1, n):
            for i in range(k):
                temp = p[:]
                temp.insert(i, j)
                r.append(temp)
    return r
    
def get_comb(k, n):
    '''
    get k items out of total n
    '''
    if k == 0:
        return []
    r = []
    if k == 1:
        for i in range(n):
            r.append([i])
        return r
    r1 = get_comb(k-1, n)
    for sr in r1:
        for i in range(sr[-1] + 1, n):
            if i not in sr:
                temp = sr[:]
                temp.append(i)
                r.append(temp)
    return r

def is_dividable(n, prime_list):
    for p in prime_list:
        if n % p == 0:
            return True
    return False

def gen_prime(n):
    r = [2]
    i = 3
    while i <= n:
        if not is_dividable(i, r):
            r.append(i)
        i += 2
    return r

def get_prime_list():
    f = open('prime_list.txt', 'r')
    prime_list = eval(f.read())
    return prime_list

# Test
if __name__ == '__main__':
    def test_process_func(func_input):
        print 'func_input:', func_input
        return 0
    
    # Set test case input file
    f = open(default_working_folder + default_file_name + '.in', 'r')
    old_content = f.read()
    f.close()
    f = open(default_working_folder + default_file_name + '.in', 'w')
    f.write('''4
5
Yeehaw
NSM
Dont Ask
B9
Googol
10
Yeehaw
Yeehaw
Googol
B9
Googol
NSM
B9
NSM
Dont Ask
Googol
5
Yeehaw
NSM
Dont Ask
B9
Googol
7
Googol
Dont Ask
NSM
NSM
Yeehaw
Yeehaw
Googol
4
Zol
Zolz
Zollz
Zolzz
0
0
3
'AZ'
'BZ'
'CZ'
''')
    f.close()

    def test_input_dividing_func(input_lines):
        total_case = int(input_lines.pop(0))
        case_inputs = []
        for i in range(total_case):
            engine_num = int(input_lines.pop(0))
            engines = input_lines[:engine_num]
            del input_lines[:engine_num]
            query_num = int(input_lines.pop(0))
            queries = input_lines[:query_num]
            del input_lines[:query_num]
            case_inputs.append([engines, queries])
        return case_inputs
    
    run_proc(test_process_func, test_input_dividing_func)
    
    # restore file used in test case back to its original content.
    f = open(default_working_folder + default_file_name + '.in', 'w')
    f.write(old_content)
    f.close()
