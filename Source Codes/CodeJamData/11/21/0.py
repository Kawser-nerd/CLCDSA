import sys
import math

def solve(matches):
    M = len(matches)
    played = [0] * M
    won = [0] * M
    won_against = []
    played_against = []
    for i in range(M):
        won_against.append([])
        played_against.append([])
        for j in range(M):
            ch = matches[i][j]
            if ch=='1':
                won[i] += 1
            if ch!='.':
                played[i] += 1
            won_against[i].append(1 if ch=='1' else 0)
            played_against[i].append(ch!='.')
    WP = [won[i]*1./played[i] for i in range(M)]
    OWP = [sum((won[j] - won_against[j][i])*1./(played[j]-1) for j in range(M) if played_against[i][j]) / played[i] for i in range(M)]
    OOWP = [sum(OWP[j] for j in range(M) if played_against[i][j]) / played[i] for i in range(M)]
    return [WP[i]*0.25 + OWP[i]*0.5 + OOWP[i]*0.25 for i in range(M)]

def readline():
    return input.readline().strip(' \r\n\t')

def do_test(input):
    M = int(readline())
    matches = [readline() for i in range(M)]
    res = solve(matches)
    return res

input = sys.stdin

N = int(readline())

for test in range(N):
    answer = do_test(input)
    print 'Case #%d:' % (test+1)
    for num in answer:
        print num
    sys.stdout.flush()
    
