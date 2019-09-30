# -*- coding: utf-8 -*-
input()
numbers = list(map(int, input().split()))
 
count = 0
while(True):
	if sum(list(map(lambda x: x % 2, numbers))) == 0:
		numbers = list(map(lambda x: x / 2, numbers))
		count += 1
	else:
		break
print(count)