#!/usr/bin/env python

import sys


def get_count(P,K,L_lst):
    L_lst.sort(reverse=1)
    keys_list = []
    for x in range(1,P+1):
        keys_list += [x for y in range(K)]
    if len(L_lst) > len(keys_list):
        return "Impossible"
    keys_list = keys_list[:len(L_lst)]
    return sum(map(lambda a,b: a*b, keys_list,L_lst))

lines = open(sys.argv[1]).readlines()
prob_count = int(lines[0])
lines = lines[1:]
assert(len(lines) == 2*prob_count)
params = []
for i in range(0,len(lines),2):
    P,K,L = [int(x) for x in lines[i].split()]
    L_lst = [int(x) for x in lines[i+1].split()]
    assert(len(L_lst) == L)
    params.append([P,K,L_lst])

for i,(P,K,L_lst) in enumerate(params):
    print "Case #%d: %d" %(i+1,get_count(P,K,L_lst))
