#!/usr/bin/env python

import sys

filename=sys.argv[1]
inputfile=file(filename, 'r')
numcases=int(inputfile.readline().strip())
for case in range(1,numcases+1):
    K = int(inputfile.readline().strip())
    data = map(int, inputfile.readline().strip().split(" "))
    n=data[0]
    dis=data[1:]
    cards=range(K)
    remainingcards=range(K)
    remainingcardpos=0
    for cardvalue in range(K):
	remainingcardpos=(cardvalue+remainingcardpos)%len(remainingcards)
	card=remainingcards[remainingcardpos]
	cards[card]=cardvalue+1 # cards are numbered 1,2...
	del remainingcards[remainingcardpos]
    sys.stdout.write("Case #%d:" % case)
    for di in dis:
	sys.stdout.write(" %d" % cards[di-1])
    sys.stdout.write("\n")
