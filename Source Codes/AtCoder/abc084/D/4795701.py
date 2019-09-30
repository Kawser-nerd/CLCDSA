import itertools
import math
from collections import deque
from collections import defaultdict
from itertools import permutations
import heapq
import bisect
INF = float("inf")

Q = int(input())
l = [0]*Q
Sum = [0]*(10**5+1)
for i in range(Q):
    l[i] = list(map(int,input().split()))

def is_prime(n):
    for i in range(2,int(math.sqrt(n))+1):
        if i * i > n:
            break
        if n % i == 0:
            return False
    return n != 1
for i in range(3,10**5+1,2):
    if is_prime(i) and is_prime((i+1)//2):
        Sum[i] = Sum[i-2]+1
    else:
        Sum[i] = Sum[i-2]

for i in range(Q):
    if l[i][1] ==1:
        print(0)
    elif l[i][0] == 1:
        print(Sum[l[i][1]])
    else:
        print(Sum[l[i][1]]-Sum[l[i][0]-2])