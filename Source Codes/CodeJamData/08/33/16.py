#! /usr/bin/python

import sys


def make_speeds(n, m, A, X, Y, Z):

    speeds = []
    for i in range(n):
        speeds.append(A[i % m])
        A[i % m] = (X*A[i%m] + Y*(i+1))%Z
  #  print speeds
    return speeds

def do_task(task_bite):

    len_task = len(task_bite)
    possible_routes = [1 for k in task_bite]
    for j in range(len_task - 1, -1, -1):
       # print j
        this_sign = task_bite[j]
        for k in range(j + 1, len_task):
            if this_sign < task_bite[k]:
                possible_routes[j] = possible_routes[j] + possible_routes[k]

  #  print possible_routes
    return sum(possible_routes) % 1000000007
    
    

###############
#    MAIN     #
###############

input_lines = file(sys.argv[1]).read().split("\n")
out_handle = file(sys.argv[2], 'w')
ncases = int(input_lines[0])
line_pos = 1

for case in range(ncases):

    print input_lines[line_pos]
    [n, m, X, Y, Z] = [int(x) for x in input_lines[line_pos].split()]
    line_pos = line_pos + 1
    
    A = [int(x) for x in input_lines[line_pos:line_pos + m]]
    line_pos = line_pos + m
    
    out_string = "Case #%i: " %(case + 1) + str(do_task(make_speeds(n, m, A, X, Y, Z)))
    print out_string
    out_handle.write(out_string + "\n")

out_handle.close()
