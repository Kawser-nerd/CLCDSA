from itertools import *
from bisect import bisect
import sys
lines = open("b.in").read().split("\n")
T = int(lines[0])

def f(N,K,sum_i):
    min_diff = [0]*K
    max_diff = [0]*K
    curr_diff = [0]*K
    first_sum = int(sum_i[0])
    last_thing = first_sum
    for i,a in enumerate(sum_i[1:]):
        curr_diff[i%K] += int(a) - last_thing
        last_thing = int(a)
        max_diff[i%K] = max(curr_diff[i%K],max_diff[i%K])
        min_diff[i%K] = min(curr_diff[i%K],min_diff[i%K])
    
    diff = list(x-n for x,n in izip(max_diff,min_diff))
    worst_diff = max(diff)
    
    move_up_min = 0
    move_up_max = 0
    move_down_min = 0
    move_down_max = 0
    for i in xrange(K):
        if min_diff[i] < 0:
            move_up_min += -min_diff[i]
            move_up_max += worst_diff - max_diff[i]
        elif max_diff[i] > worst_diff:
            move_down_min += max_diff[i] - worst_diff
            move_down_max += min_diff[i]
        else:
            move_up_max += worst_diff - max_diff[i]
            move_down_max += min_diff[i]
    
    move_up_d = move_up_max - move_up_min
    move_down_d = move_down_max - move_down_min

    move_min = move_up_min - move_down_max
    move_d = move_down_d + move_up_d
    move_min %= (K)
    move_amt = first_sum % (K)
    # print move_amt,move_min,move_d
    if move_amt < move_min:
        move_min -= K
    if move_min + move_d >= move_amt:
        return worst_diff
    return worst_diff + 1
curr_i = 1
for i in xrange(1,T+1):
    N,K = tuple(int(j) for j in lines[curr_i].split(' '))
    curr_i += 1
    out = f(N,K,lines[curr_i].split(' '))
    curr_i += 1
    print "Case #%d: %s" % (i, out)