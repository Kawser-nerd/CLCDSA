##import numpy as np
import math
##import time
##import os
##import shutil

input_file_name = './B-large.in'
output_file_name = './B-large.out'
    

if __name__ == '__main__':

    input_file = open(input_file_name, 'r')
    output_file = open(output_file_name, 'w')

    # get info from input file
    file_line = input_file.readline()
    file_line = file_line.replace('\n', '')
    num_cases = int(file_line)

    case_num = 1
    while True:
        file_line = input_file.readline()
        if file_line == '' or file_line == '\n':
            input_file.close()
            break
        file_line = file_line.replace('\n', '')
        file_line_list = file_line.split()
        C = float(file_line_list[0])
        F = float(file_line_list[1])
        X = float(file_line_list[2])

        if C >= X:
            total_time = X/2.0
        else:        
            n = max(0.0, float(math.floor((F*X - 2.0*C)/(C*F))))
            total_time = 0.0
            for n_i in range(int(n)):
                total_time += C/(2.0 + n_i*F)
            total_time += X/(2.0 + n*F)

        output_file.write('Case #' + str(case_num) + ': %0.7f\n' % total_time)
        print(case_num)
        case_num += 1
        
    output_file.close()











