# coding: utf-8 -*-

n = int(input())

t, a = map(int, input().split())

h = list(map(int, input().split()))

h2 = [abs((t - i * 0.006) - a) for i in h]

print(h2.index(min(h2)) + 1)