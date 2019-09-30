# -*- coding:utf-8 -*-
N = int(input())
a = list(map(int, input().split()))

sum = 0
cost = 0

for x in a:
    sum += x

ave = round(sum / N)

for x in a:
    cost += (x - ave) ** 2

print(cost)