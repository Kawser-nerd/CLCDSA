# -*- coding: utf-8 -*-
input()

numbers = sorted(list(map(int, input().split())))

alice = bob = 0

while(len(numbers)):
	if len(numbers) == 1:
		alice += numbers.pop()
	else:
		alice += numbers.pop()
		bob += numbers.pop()

print(alice - bob)