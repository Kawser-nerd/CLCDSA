#-*- coding:utf-8 -*-
# AUTHOR:
# FILE:     q3.py
# ROLE:     TODO (some explanation)
# CREATED:  2015-04-11 17:49:44
# MODIFIED: 2015-04-11 20:43:11
import sys

symbol_table = ['1','i','j','k']
flag_table = [1,1,1,1,1,-1,1,-1,1,-1,-1,1,1,1,-1,-1]
index_table = [0,1,2,3,1,0,3,2,2,3,0,1,3,2,1,0]

base_ascii = ord('i') - 1

def load_cases(path):
    case_list = []
    with open(path, 'r') as fh:
        case_num = int(fh.readline().strip("\r\n"))
        for i in range(0, case_num):
            L, X = filter(None, fh.readline().strip("\r\n").split(" "))
            pattern =[ord(c) - base_ascii for c in fh.readline().strip("\r\n")]
            case_list.append((int(L),int(X), pattern))
    return case_list

def calculate_val(a,b):
    pos = a * 4 + b
    return flag_table[pos], index_table[pos]

def check_final_value(L, X,  pattern):
    if X == 0 or X % 4 == 0:
        return False
    is_same = True
    pivot = pattern[0]
    for k in range(1, L):
        if pattern[k] != pivot:
            is_same = False
            break

    if is_same == True:
        return False

    k = 0
    accu_flag = 1
    accu_val = 0
    while k < L:
        #print accu_val, pattern[k]
        flag, accu_val = calculate_val(accu_val, pattern[k])
        accu_flag *= flag
        #print k, accu_flag, symbol_table[accu_val]
        k += 1

    #print accu_flag, symbol_table[accu_val]
    X1 = (X - 1) % 4
    #print X1
    cur_val = accu_val
    cur_flag = accu_flag

    for m in range(0, X1):
        accu_flag *= cur_flag
        flag, accu_val = calculate_val(accu_val, cur_val)
        accu_flag *= flag
        #print accu_flag, symbol_table[accu_val]

    if accu_val != 0 or accu_flag != -1:
        #print 'check final value failed'
        return False
    return True

def calculate_case(case):
    L, X, pattern = case
    if check_final_value(L, X, pattern) == False:
        return False

    accu_flag = 1
    accu_val = 0
    k = 0
    str_len = L * X
    for target_val in [1,2,3]:
        if k >= str_len:
            return False
        cur_val = 0
        #print 'target_val: ', symbol_table[target_val]
        while k < str_len and cur_val != target_val:
            flag, cur_val = calculate_val(cur_val, pattern[k % L])
            accu_flag *= flag
            #print k, accu_flag, symbol_table[cur_val]
            k += 1
        flag, accu_val = calculate_val(accu_val, cur_val)
        accu_flag *= flag

        if cur_val != target_val:
            return False

    return True

if __name__ == '__main__':
    if len(sys.argv) != 3:
        print 'Usage: q2.py input_file output_file'
        sys.exit()

    input_file = sys.argv[1]
    output_file = sys.argv[2]

    case_list = load_cases(input_file)
    with open(output_file, 'w') as fh:
        case_id = 1
        for case in case_list:
            #print case_id
            is_ok = calculate_case(case)
            fh.write('Case #%d: %s\n' %(case_id, 'YES' if is_ok == True else 'NO'))
            case_id += 1

