infilecode = "CLI"

import sys
mapping = {"A":"A", "B":"B", "C":"C", "D":"D", "E":"E", "X":"example", "S":"-small", "L":"-large", "P":"-practice", "0":"-attempt0", "1":"-attempt1", "2":"-attempt2", "z":"-1", "Z":"-2", "I":".in", "T":".txt"}
infile = "".join(mapping[c] for c in infilecode)
outfile = infile.replace(".in", "") + ".out.txt"
sys.stdin = open(infile, 'r')
output = open(outfile, 'w')

T = int(input())

for case in range(1,T+1):
    
    N, K = map(int,input().split())
    print(N,K)


    sizes = [N,N+1]
    num = [1,0]

    while K > sum(num):
        a, b = sizes
        K -= sum(num)
        sizes = [(a-1)//2, b//2]
        if a%2 == 0:
            num = [num[0], num[0]+num[1]*2]
        else:
            num = [num[0]*2+num[1], num[1]]
        
        print(sizes, num, K)


    if K <= num[1]:
        size = sizes[1]
    else:
        size = sizes[0]

    R = size//2
    L = (size-1)//2

    answer = str(R) + " " + str(L)





    print("Case #%d:" % case, answer)
    print("Case #%d:" % case, answer, file = output)

    
    #if case == 16:        break
