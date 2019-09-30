#!/usr/bin/env python3
import sys

def get_ints():
	for line in sys.stdin:
		for word in line.split():
			yield int(word)
	return

ints = get_ints()

def low(pattern):
	return int(''.join(pattern).replace('*','0'))

def high(pattern):
	return int(''.join(pattern).replace('*','9'))

def base_case(pattern):	
	for i in range(1,len(pattern)):
		count_valid(pattern[i:]+pattern[:i],pattern)

def count_valid(pattern,org):
	if low(pattern) > B or high(pattern) < A: return
	if low(pattern) >= A and high(pattern) <= B:
		subtotal=1
		for a in pattern:
			if a == '*':
				subtotal = subtotal * 10;
		global total
		total = total + subtotal
	else:
		poz = 0
		while pattern[poz] != '*': poz=poz+1
		for i in range(10):
			count_valid(pattern[:poz]+[str(i)]+pattern[poz+1:],org)

def match(pattern, value):
	for i in range(len(pattern)):
		if pattern[i] != '*' and pattern[i] != value[i]:
			return False
	return True

def cyclicity(num,div):
	ls = list(str(num))
	length = len(ls)//div
	cyclic = 1
	for i in range(1,length):
		rot = int(''.join(ls[i:]+ls[:i]))
		if A <= rot <= B:
			cyclic = cyclic+1
	return cyclic * (div-1)


T = next(ints)
for t in range(T):
	global total
	total = 0
	A = next(ints)
	B = next(ints)
	i = A
	stars=[]
	step = 1
	try:
		while 1:
			#invariant: current pattern (i+stars) is completely in range
			while i%10 == 0 and (i+10)*step-1 <= B:
				#I can add a star to the pattern
				step = step*10
				stars.append('*')
				i=i//10
			base_case(list(str(i))+stars)
			i=i+1
			while (i+1)*step-1 > B:
				#step to big to increment
				step = step//10
				stars.pop() #throws exception when done
				i=i*10
#			if step == 0: break 
	except IndexError:
		pass
	#remove cyclic numbers
	length = len(str(A))
	if length%2 == 0:
		shift = 10**(length//2)
		i = A//shift
		mask = shift+1
		if i*mask < A: i=i+1
		while i*mask <= B:
			if i*mask in [1111*a for a in range(10)]+[111111*a for a in range(10)]:
				i=i+1
				continue
			amount = cyclicity(i*mask,2)
			total = total-amount
			i = i+1
	if length%3 == 0:
		shift = 10**(length//3)
		i = A//shift**2
		mask = shift**2+shift+1
		if i*mask < A: i=i+1
		while i*mask <= B:
			if i*mask in [111111*a for a in range(10)]:
				i=i+1
				continue
			total = total-cyclicity(i*mask,3)
			i = i+1
	if length == 4:
		shift = 10
		i = A//1000
		if i*1111 < A: i=i+1
		while i*1111 <= B:
			total = total-3
			i = i+1
	if length == 5:
		shift = 10
		i = A//10000
		if i*11111 < A: i=i+1
		while i*11111 <= B:
			total = total-4
			i = i+1
	if length == 6:
		shift = 10
		i = A//100000
		if i*111111 < A: i=i+1
		while i*111111 <= B:
			total = total-5
			i = i+1
	if length%7 == 0:
		shift = 10
		i = A//1000000
		if i*1111111 < A: i=i+1
		while i*1111111 <= B:
			total = total-6
			i = i+1
	print("Case #",t+1,": ",total//2,sep='')
