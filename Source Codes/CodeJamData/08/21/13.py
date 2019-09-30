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
    n = int(fin.readline())
    
    fout.write("Case #%d: %s\n" % (casenr+1, s))
    