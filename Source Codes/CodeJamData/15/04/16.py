#-*- coding:utf-8 -*-
# AUTHOR:   
# FILE:     q4.py
# ROLE:     TODO (some explanation)
# CREATED:  2015-04-11 17:19:43
# MODIFIED: 2015-04-11 17:37:16

import sys

def load_cases(path):
    case_list = []
    with open(path, 'r') as fh:
        case_num = int(fh.readline().strip("\r\n"))
        for i in range(0, case_num):
            case = filter(None, fh.readline().strip("\r\n").split(" "))
            case_list.append([int(item) for item in case])
    return case_list


def calculate_case(case):
    X = case[0]
    R = case[1]
    C = case[2]
    if R > C:
        R = case[2]
        C = case[1]

    if (R * C) % X != 0 or X >= 7:
        return False
    elif X == 1 or X == 2:
        return True
    elif X == 3:
        if R == 1:
            return False
        else:
            return True
    elif X == 4:
        if R < 3:
            return False
        else:
            return True
    elif X == 5:
        if R < 3:
            return False
        elif R == 3:
            if C == 5:
                return False
            else:
                return True
        else:
            return True
    elif X == 6:
        if R < 4:
            return False
        else:
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
            G_win = calculate_case(case)
            fh.write('Case #%d: %s\n' %(case_id, 'GABRIEL' if G_win == True else 'RICHARD'))
            case_id += 1

