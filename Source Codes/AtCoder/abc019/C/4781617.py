# encoding: utf-8
import sys
input = sys.stdin.readline
inf = 10 ** 18

N = int(input())
a = list(map(int, input().split()))

a_id = list(a)
for i, ai in enumerate(a):
    ai_tmp = ai
    while ai_tmp > 0 and ai_tmp & 1 == 0: ai_tmp = ai_tmp >> 1
    a_id[i] = ai_tmp

a_id = set(a_id)
print(len(a_id))