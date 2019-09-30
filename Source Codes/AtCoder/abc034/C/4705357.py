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
import numpy as np
import copy
from collections import defaultdict, Counter
from itertools import product
from bisect import bisect_left, bisect_right

def s_inpl(): return map(int,input().split())
def inpl(): return list(map(int, input().split()))

W, H = s_inpl()

W -= 1
H -= 1

MOD = 1000000007

# ???
def power(a, b):
    if b == 0:
        return 1
    elif b % 2 == 0:
        d = power(a, b/2)
        return (d * d) % MOD
    elif b % 2 == 1:
        return (a * power(a, b-1)) % MOD

def div(a, b):
    return (a * power(b, MOD-2)) % MOD

print(div(math.factorial(W+H), (math.factorial(W) % MOD) * (math.factorial(H) % MOD)))