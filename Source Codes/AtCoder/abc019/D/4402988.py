import sys
# A,B,C =
N = int(input())

# S = str(input())
# L = len(S)
# T = str(input())
#farest point from 1
dist=0
for i in range(1,N):

    print("? {0} {1}".format(1, i+1), flush=True)
    rep = int(input())
    if rep>dist:
        dist = rep
        next = i+1
#farest point from (farest point from 1)
for i in range(0,N):
    if i+1 == next:
        continue
    print("? {0} {1}".format(next, i+1), flush=True)
    rep = int(input())
    if rep>dist:
        dist = rep

print("! " + str(dist))