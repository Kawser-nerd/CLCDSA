import numpy as np
import math
##import time
##import os
##import shutil

input_file_name = './D-large.in'
output_file_name = './D-large.out'
    

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
        N = int(file_line)
        file_line = input_file.readline()
        N_list = map(float, file_line.split())
        file_line = input_file.readline()
        K_list = map(float, file_line.split())
        
        N_list.sort()
        K_list.sort()

        # first calc fair wins
        N_index = 0
        K_index = 0
        ken_wins = 0
        while True:
            if N_index == N or K_index == N:
                break
            if K_list[K_index] > N_list[N_index]:
                ken_wins += 1
                N_index += 1
                K_index += 1
            else:
                K_index += 1
        fair_wins = N - ken_wins

        # then calc cheat wins
        N_index = 0
        K_index = 0
        cheat_wins = 0
        while True:
            if N_index == N or K_index == N:
                break
            if N_list[N_index] > K_list[K_index]:
                cheat_wins += 1
                N_index += 1
                K_index += 1
            else:
                N_index += 1

        output_file.write('Case #' + str(case_num) + ': ' + str(cheat_wins) + ' ' +
                          str(fair_wins) + '\n')          
        print(case_num)
        case_num += 1
        
    output_file.close()











