import numpy as np
import math
##import time
##import os
##import shutil

input_file_name = './C-large.in'
output_file_name = './C-large.out'
    

if __name__ == '__main__':

    input_file = open(input_file_name, 'r')
    output_file = open(output_file_name, 'w')

    # get info from input file
    file_line = input_file.readline()
    file_line = file_line.replace('\n', '')
    num_cases = int(file_line)

    case_num = 1
    while True:
        transpose_at_end = False
        impossible = False
        file_line = input_file.readline()
        if file_line == '' or file_line == '\n':
            input_file.close()
            break
        file_line = file_line.replace('\n', '')
        file_line_list = file_line.split()
        R = int(file_line_list[0])
        C = int(file_line_list[1])
        M = int(file_line_list[2])
        F = R*C - M # not mines

        if R > C:
            transpose_at_end = True
            C_copy = C*1
            C = R*1
            R = C_copy*1

        grid_array = np.zeros((R, C), dtype = np.int)

        if F == 0:
            impossible = True
        elif F == 1:
            grid_array[0, 0] = 1
        elif R == 1:
            grid_array[0, :F] += 1
        elif F == 2 or F == 3 or F == 5 or F == 7:
            print(str(F) + ' check') ##
            impossible = True
        elif R == 2 and (F % 2 == 1):
            impossible = True
        else:
            if F > C*(R - 1):
                max_height = min(int(math.sqrt(F) + 1), R)
            else:
                max_height = min(int(math.sqrt(F)), R)
            c_i = 0
            while (F >= max_height):
                    grid_array[:max_height, c_i] += 1
                    F -= max_height
                    c_i += 1
            if F > 0:
                if F != 1:
                    grid_array[:F, c_i] += 1
                else:
                    grid_array[:2, c_i] += 1
                    grid_array[max_height - 1, c_i - 1] = 0

        if transpose_at_end == True:
            grid_matrix = np.matrix(grid_array)
            grid_matrix = grid_matrix.T
            grid_array = np.array(grid_matrix)
            C_copy = C*1
            C = R*1
            R = C_copy*1
            

        output_file.write('Case #' + str(case_num) + ':' + '\n')
        if impossible == True:
            output_file.write('Impossible' + '\n')
        else:
            for R_i in range(R):
                for C_i in range(C):
                    if R_i == 0 and C_i == 0:
                        output_file.write('c')
                    elif grid_array[R_i, C_i] == 1:
                        output_file.write('.')
                    elif grid_array[R_i, C_i] == 0:
                        output_file.write('*')
                output_file.write('\n')
                
                        
        print(case_num)
        case_num += 1
        
    output_file.close()











