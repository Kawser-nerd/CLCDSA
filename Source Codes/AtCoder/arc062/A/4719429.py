import math
from decimal import *

N = int(input())
_input = []
for i in range(N):
    _input.append(list(map(int,input().split())))

total_T = 1
total_A = 1

for t,a in _input:
    #n = max(math.ceil(total_T/t),math.ceil(total_A/a))
    n = max(-(-total_T//t), -(-total_A//a))
    total_T = int(t*n)
    total_A = int(a*n)

print(total_A+total_T)