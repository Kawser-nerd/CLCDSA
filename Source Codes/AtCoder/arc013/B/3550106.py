# coding:utf-8

import sys
from operator import itemgetter

input = sys.stdin.readline


def inpl(): return list(map(int, input().split()))


C = int(input())
boxes = []
for i in range(C):
    size = inpl()
    size.sort()
    boxes.append(size)

ans = 1
for i in range(3):
    ans *= max(boxes, key=itemgetter(i))[i]

print(ans)