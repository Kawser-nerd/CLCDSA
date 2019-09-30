import sys

infile = "A-large.in"
outfile = "A-large.out"
sys.stdin = open(infile, 'r')
output = open(outfile, 'w')

T = int(input())
for case in range(1,T+1):

    ## Read inputs and calculate answer
    S,K = input().split(" ")
    print("S = "+S)
    print("K = "+K)
    K = int(K)

    answer = 0
    for i in range(len(S)-K+1):
        if S[i]=="-":
            answer+=1
            mid = ""
            for j in range(K):
                if S[i+j]=="-":
                    mid+="+"
                else:
                    mid+="-"
            S = S[:i]+mid+S[i+K:]
            print("Case #%d:" % case, answer, S)

    if S!="+"*len(S):
        answer="IMPOSSIBLE"
    else:
        answer=str(answer)

    ##

    print("Case #%d:" % case, answer)
    print("Case #%d:" % case, answer, file = output)
