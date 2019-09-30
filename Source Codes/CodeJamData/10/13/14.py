#!/usr/bin/env python

import sys

def isWin(a, b):
    if a < b:
        temp = a
        a = b
        b = temp
    
    my_turn = True
    while True:
        # If they're equal, you win if it's not your turn
        if a == b:
            return not my_turn

        # If you have a choice, you win if it's your turn
        if a >= (2 * b):
            return my_turn
        
        # Otherwise, keep going
        my_turn = not my_turn
        temp = a - b
        a = b
        b = temp

def main():
    nCases = int(sys.stdin.readline())
    case = 0

    for line in sys.stdin.readlines():
        case += 1
        if case > nCases:
            break;
        
        [a_min, a_max, b_min, b_max] = [int(x) for x in line.split()]
        
        wins = 0
        for a in range(a_min, a_max + 1):
            for b in range(b_min, b_max + 1):
                if isWin(a, b):
                    wins += 1

        print 'Case #%d: %d' % (case, wins)
    
main()
