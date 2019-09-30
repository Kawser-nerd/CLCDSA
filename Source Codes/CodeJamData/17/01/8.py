infilecode = "ALI"

import sys
mapping = {"A":"A", "B":"B", "C":"C", "D":"D", "E":"E", "X":"example", "S":"-small", "L":"-large", "P":"-practice", "0":"-attempt0", "1":"-attempt1", "2":"-attempt2", "I":".in", "T":".txt"}
infile = "".join(mapping[c] for c in infilecode)
outfile = infile.replace(".in", "") + ".out.txt"
sys.stdin = open(infile, 'r')
output = open(outfile, 'w')

T = int(input())

for case in range(1,T+1):
    S, K = input().split()
    print(S,K)
    
    K=int(K)
    S = list(S)
    L = len(S)


    flips = 0
    for i in range(L-K+1):
        if S[i] == "-":
            flips += 1
            for j in range(i,i+K):
                S[j] = {"+":"-", "-":"+"}[S[j]]
            #print(*S)

    if S == ["+"]*L:
        answer = flips
    else:
        answer = "IMPOSSIBLE"


    print("Case #%d:" % case, answer)
    print("Case #%d:" % case, answer, file = output)