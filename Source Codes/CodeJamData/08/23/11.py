from time import time
import psyco
import re
import math
psyco.full()

fin = open("1_input.txt","r")
fout = open("1_output.txt","w")
cases = int(fin.readline())


t0 = time()
for casenr in range(cases):
    K = int(fin.readline())
    indices = map(int, [e for e in fin.readline().split()])
    indices = indices[1:]
    #print indices 
    #print K
    open_indices = []
    closed_indices = []
    for i in range(1,K+1):
        open_indices.append(i)
        closed_indices.append(i)
    
    current_number = 1
    current_position = -1
    #print open_indices
    while open_indices:
        next_index = (current_position + current_number) % len(open_indices) 
        #print current_position, current_number, len(open_indices), next_index
        #print "saving",current_number,"at pos",open_indices[next_index]
        closed_indices[open_indices[next_index]-1] = current_number
        open_indices.pop(next_index)
        current_position = next_index - 1
        current_number += 1
        #print closed_indices
    fout.write("Case #%d:" % (casenr+1))
    for ind in indices:
        fout.write(" %d" % (closed_indices[ind-1]))
    fout.write("\n")
    