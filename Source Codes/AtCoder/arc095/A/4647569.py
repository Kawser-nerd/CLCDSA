from math import *

n = int(input())

a = [int(x) for x in input().split()]

a_sort = sorted(a)

median_right = a_sort[floor(len(a_sort) / 2)]
median_left = a_sort[floor(len(a_sort) / 2) - 1]

for i in range(len(a)):
	if a[i] > median_left:
		print(median_left)
	else:
		print(median_right)