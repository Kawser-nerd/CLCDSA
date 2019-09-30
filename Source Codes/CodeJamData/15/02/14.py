#-*- coding:utf-8 -*-
# AUTHOR:   
# FILE:     q2.py
# ROLE:     TODO (some explanation)
# CREATED:  2015-04-11 11:16:49
# MODIFIED: 2015-04-11 16:08:04

import sys
import math

def load_cases(path):
    case_list = []
    with open(path, 'r') as fh:
        case_num = int(fh.readline().strip("\r\n"))
        for i in range(0, case_num):
            D = int(fh.readline().strip("\r\n"))
            P = filter(None, fh.readline().strip("\r\n").split(" "))
            if D != len(P):
                print 'incorrect file at case %d' %i
                sys.exit()
            case_list.append([int(item) for item in P])
    return case_list

def calculate_case(P):
    max_num = max(P)
    return min(sum([int((num - 0.5) / m) for num in P]) + m for m in range(max_num, 0, -1))

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
            time = calculate_case(case)
            fh.write('Case #%d: %d\n' %(case_id, time))
            case_id += 1
