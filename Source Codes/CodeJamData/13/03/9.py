#!/usr/bin/python3.2

filename = 'C-large-2.in'
FILE = open(filename)
T = int(FILE.readline())

cache = [int(x) for x in open('cache.txt').read().splitlines()[1:]]

def count(a,b):
    c = 0
    for elem in cache:
        if elem > b:
            return c
        if elem >= a:
            c += 1

for i in range(1,T+1):
    rawline = FILE.readline().split(' ')
    a,b = int(rawline[0]), int(rawline[1])

    print('Case #' + str(i) + ': ' + str(count(a,b)))