#!~/usr/bin/python3.2

import copy

filename = 'D-large.in'

FILE = open(filename)
T = int(FILE.readline())

def solve(keys,chests, order):
    for i,chest in enumerate(chests):
        available_moves = set([key for key in keys if keys[key] > 0])
        if chest['req'] in available_moves:
            newKeys = copy.copy(keys)
            newKeys[chest['req']] -= 1
            for key in chest['con']: newKeys[key] += 1

            newChests = chests[:i] + chests[i+1:]
            newOrder = copy.copy(order)
            newOrder.append(chest['ix'])

            if len(newChests) == 0: return str(newOrder)

            if solvable(newKeys,newChests):
                temp = solve(newKeys,newChests,newOrder)
                if (temp != 'IMPOSSIBLE'): return temp

    return 'IMPOSSIBLE'

def solvable(keys,chests):
    #If we cheat, can we win?
    for chest in chests: chest['flag'] = 0

    keySet = set([key for key in keys if keys[key] >= 1])
    if len(keySet) < 1: return False

    flag = 1 #something occurring
    while flag:
        flag = 0
        for chest in chests:
            if (chest['req'] in keySet) and (chest['flag'] == 0):
                flag = 1
                chest['flag'] = 1
                keySet = keySet.union(set(chest['con']))

    for chest in chests:
        if chest['flag'] == 0: return False

    #Is the final state positive for all keys?
    num = copy.copy(keys)

    for chest in chests:
        num[chest['req']] -= 1
        for k in chest['con']:
            num[k] += 1

    for i in num:
        if num[i] < 0: return False

    return True

for t in range(1,T+1):
    k,n = [int(x) for x in FILE.readline().split(' ')]
    keys = {i:0 for i in range(1,201)}
    for key in [int(x) for x in FILE.readline().split(' ')]: keys[key] += 1

    chests = []
    for i in range(0,n):
        raw = FILE.readline().split(' ')
        chests.append( { 'req':int(raw[0]), 'con':[int(x) for x in raw[2:]], 'ix':i+1 } )


    if solvable(keys,chests):
        sol = solve(keys,chests,[])
        if sol != 'IMPOSSIBLE':
            sol = str(sol)[1:-1].split(', ')
            sol = ' '.join(sol)
    else:
        sol = 'IMPOSSIBLE'
    print('Case #' + str(t) + ': ' + sol)