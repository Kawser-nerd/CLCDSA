infilecode = "BLI"

import sys
mapping = {"A":"A", "B":"B", "C":"C", "D":"D", "E":"E", "X":"example", "S":"-small", "L":"-large", "P":"-practice", "0":"-attempt0", "1":"-attempt1", "2":"-attempt2", "I":".in", "T":".txt"}
infile = "".join(mapping[c] for c in infilecode)
outfile = infile.replace(".in", "") + ".out.txt"
sys.stdin = open(infile, 'r')
output = open(outfile, 'w')

T = int(input())

for case in range(1,T+1):
    N = int(input())
    print(N)
    
    a = str(N)
    l = len(a)

    for i in range(l-1,0,-1):
        if a[i] >= a[i-1]:
            continue
        a = a[:i]+"0"*(l-i)
        N=int(a)-1
        a=str(N)

    answer = a

    print("Case #%d:" % case, answer)
    print("Case #%d:" % case, answer, file = output)