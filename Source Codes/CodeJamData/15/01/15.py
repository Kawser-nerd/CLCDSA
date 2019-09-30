#-*- coding:utf-8 -*-
# AUTHOR:   
# FILE:     q1.py
# ROLE:     TODO (some explanation)
# CREATED:  2015-04-11 10:34:32
# MODIFIED: 2015-04-11 10:51:08

import sys

def load_case(path):
    case_list = []
    with open(path, 'r') as fh:
        case_num = int(fh.readline().strip("\r\n"))
        for k in range(0,case_num):
            case = []
            s_max, digits = filter(None, fh.readline().split(' '))
            s_max = int(s_max)
            for j in range(0, s_max + 1):
                case.append(ord(digits[j]) - ord('0'))
            case_list.append(case)
    return case_list

def calculate_case(case):
    people_num = 0
    num_to_invite = 0
    for k in range(0, len(case)):
        new_invite = k - people_num
        new_invite = new_invite if new_invite > 0 else 0
        num_to_invite += new_invite
        people_num += (case[k] + new_invite)
    return num_to_invite

if __name__== '__main__':
    if len(sys.argv) != 3:
        print 'Usage: q1 input output'
        sys.exit()

    input_file  = sys.argv[1]
    output_file = sys.argv[2]
    case_list =  load_case(input_file)

    with open(output_file, 'w') as fh:
        for k in range(0, len(case_list)):
            num =  calculate_case(case_list[k])
            fh.write("Case #%d: %d\n" %(k + 1, num))
