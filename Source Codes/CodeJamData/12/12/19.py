#!/usr/bin/python3

from sys import argv

infile = open(argv[1])
cases = int(infile.readline())
for i in range(cases):
    n = int(infile.readline())
    needed = []
    for j in range(n):
        needed.append(list(map(int, infile.readline().split())))
    games = 0
    stars = 0
    earned = [0 for j in range(n)]
    toobad = False
    games = 0
    while stars < 2 * n:
        level = None
        earn = 0
        mostneeded = -1
        spam = True # try to beat level one
        for j in range(n):
            # Try to find a way to get two stars
            if stars >= needed[j][1] and earned[j] == 0:
                level = j
                earn = 2
                break
            # Try to find a way to get one star using level two
            elif stars >= needed[j][1] and earned[j] == 1:
                level = j
                earn = 1
                spam = False
                # but keep trying for the two stars!
            # If we can only get level one, do it for the level that needs the most stars for level 2
            elif spam and stars >= needed[j][0] and earned[j] == 0 and needed[j][1] > mostneeded:
                level = j
                earn = 1
                mostneeded = needed[j][1]
        if earn == 2:
            earned[level] = 2
            stars += 2
        elif earn == 1:
            earned[level] += 1
            stars += 1
        else:
            toobad = True
            break
        games += 1
    if toobad:
        print('Case #{}: Too Bad'.format(i+1))
    else:
        print('Case #{}: {}'.format(i+1, games))
