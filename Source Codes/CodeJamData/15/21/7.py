from queue import Queue

def minsteps(start,goal):
    if start == goal: return 0

    # start je 100...000
    # goal ma rovnako cifier ako start

    best = int(goal) - int(start)
    bmedzi = ''

    # pre nejaky split robime to ze najskor inc-ujeme posledne cifry, potom reverz

    C = len(start)
    for cif in range(C):
        rgoal = goal[::-1]
        medzi = start[:C-cif] + rgoal[C-cif:]
        if medzi[::-1] > goal: continue
        toto = int(medzi) - int(start) + 1
        toto += int(goal) - int( medzi[::-1] )
        # print(start,'->',medzi,'->',medzi[::-1],'->',goal)
        if toto < best:
            best = toto
            bmedzi = medzi

    # print('minsteps',start,goal,'return',best,'::',start,'->',medzi,'->',medzi[::-1],'->',goal)
    return best

def solve(goal):
    start = '1'
    answer = 1
    while len(start) < len(goal):
        answer += minsteps(start, '9'*len(start)) + 1 
        start += '0'
    answer += minsteps(start,goal)
    return answer

T = int(input())
for t in range(1,T+1):
    goal = input().strip()
    answer = solve(goal)
    if goal != '1':
        goal = str( int(goal)-1 )
        answer = min( answer, 1+solve(goal) )
    print('Case #{}: {}'.format(t,answer))
