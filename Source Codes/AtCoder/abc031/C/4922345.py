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
from collections import defaultdict
from collections import Counter
from collections import deque
# ?? A={a, b, c}, B={d, e}:????A×B={(a,d),(a,e),(b,d),(b,e),(c,d),(c,e)}: product(A, B)
from itertools import product
# ?? P!: permutations(seq), ?? {}_len(seq) P_n: permutations(seq, n)
from itertools import permutations
# ????? {}_len(seq) C_n: combinations(seq, n)
from itertools import combinations
from bisect import bisect_left, bisect_right
# import numpy as np
 
# ???
dy = [0, 0, 1, -1]
dx = [1, -1, 0, 0]
INF = float("inf")
 
def i_inpl(): return int(input())
def s_inpl(): return map(int,input().split())
def l_inpl(): return list(map(int, input().split()))
 
N = i_inpl()
a = l_inpl()

ans = -INF
# ??
for i in range(N):
    a_max_score = -INF
    t_max_score = -INF
    # ??
    for j in range(N):
        if j == i:
            continue
        l, r = min(i, j), max(i, j)
        a_score, t_score = 0, 0
        for ind, ai in enumerate(a[l:r+1]):
            if (ind + 1) % 2 == 1:
                t_score += ai
            else:
                a_score += ai
        if a_score > a_max_score:
            a_max_score = a_score
            t_max_score = t_score
    ans = max(ans, t_max_score)

print(ans)