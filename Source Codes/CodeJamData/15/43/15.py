#!/usr/bin/env python3.4
import sys
import math

mi = [None]

def place(english_bag, french_bag, ambi, i):
    if i < len(ambi):
        if mi[0] != None and mi[0] < len(english_bag & french_bag):
            return
        a = place(english_bag | ambi[i], french_bag, ambi, i + 1)
        b = place(english_bag, french_bag | ambi[i], ambi, i + 1)
    else:
        conf = len(english_bag & french_bag)
        if mi[0] == None or conf < mi[0]:
            mi[0] = conf

if __name__ == '__main__':
    for test_case in range(int(sys.stdin.readline())):
        sys.stdout.write('Case #{}: '.format(test_case + 1))
        n = int(sys.stdin.readline().strip())
        english = set(sys.stdin.readline().split())
        french = set(sys.stdin.readline().split())
        ambi = []
        mi[0] = None
        for i in range(n - 2):
            ambi.append(set(sys.stdin.readline().split()))
        place(english, french, ambi, 0)
        print(mi[0])
        # print(place(english, french, ambi, 0))

