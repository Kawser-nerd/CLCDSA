#!/usr/bin/python

import sys

def emit(text, *args):
    msg = text % args
    sys.stderr.write(msg)
    sys.stdout.write(msg)

def getline():
    return sys.stdin.readline().rstrip('\n')

def parse(s):
    last_letter = ''
    letters = []
    counts = []
    for i in range(len(s)):
        if s[i] == last_letter:
            counts[-1] += 1
        else:
            letters.append(s[i])
            counts.append(1)
            last_letter = s[i]
    return (letters, counts)

def solve(strs):
    points = 0
    letters, _ = parse(strs[0])
    counts = []
    for s in strs:
        lts, cts = parse(s)
        if lts != letters:
            return "Fegla Won"
        counts.append(cts)

    for let in range(len(letters)):
        equalize = [ counts[c][let] for c in range(len(counts)) ]
        h = max(equalize)
        l = min(equalize)
        while h != l:
            ch = equalize.count(h)
            cl = equalize.count(l)
            if ch < cl:
                for i in range(len(equalize)):
                    if equalize[i] == h:
                        equalize[i] = h - 1
                        points += 1
                h = h - 1
            else:
                for i in range(len(equalize)):
                    if equalize[i] == l:
                        equalize[i] = l + 1
                        points += 1
                l = l + 1
    return points

ncases = int(getline())

for casenr in range(1, ncases+1):
    n = int(getline())
    strs = []
    for i in range(n):
        strs.append(getline())
    emit("Case #%d: %s\n", casenr, solve(strs))
