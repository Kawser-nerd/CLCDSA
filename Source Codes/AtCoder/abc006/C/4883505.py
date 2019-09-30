# https://qiita.com/_-_-_-_-_/items/34f933adc7be875e61d0
# abcde	s=input()	s='abcde'
# abcde	s=list(input())	s=['a', 'b', 'c', 'd', 'e']
# 5(1???)	a=int(input())	a=5
# 1 2	| x,y = s_inpl()   |	x=1,y=2
# 1 2 3 4 5 ... n ?	li = input().split()	li=['1','2','3',...,'n']
# 1 2 3 4 5 ... n ?	li = inpl()	li=[1,2,3,4,5,...,n]
# FFFTFTTFF ?	li = input().split('T')	li=['FFF', 'F', '', 'FF']

# INPUT
# 3
# hoge
# foo
# bar
# ANSWER
# n=int(input())
# string_list=[input() for i in range(n)]

import math
import copy
from collections import defaultdict, Counter
# ?? A={a, b, c}, B={d, e}:????A×B={(a,d),(a,e),(b,d),(b,e),(c,d),(c,e)}: product(A, B)
from itertools import product
# ?? P!: permutations(seq), ?? {}_len(seq) P_n: permutations(seq, n)
from itertools import permutations
# ????? {}_len(seq) C_n: combinations(seq, n)
from itertools import combinations
from bisect import bisect_left, bisect_right
# import numpy as np

def i_inpl(): return int(input())
def s_inpl(): return map(int,input().split())
def l_inpl(): return list(map(int, input().split()))
INF = float("inf")

N, M = s_inpl()

def solve():
    for a in range(N+1):
        b = 4*N-M-2*a
        c = M-3*N+a
        if b>=0 and c>=0:
            return a, b, c
    return -1, -1, -1

a, b, c = solve()
print("{} {} {}".format(a, b, c))