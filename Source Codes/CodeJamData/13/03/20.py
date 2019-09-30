import math

def make_num(digits, repeat_last_digit):
	num = 0
	for d in digits:
		num *= 10
		num += d
	
	if repeat_last_digit:
		r = range(len(digits)-1, -1, -1)
	else:
		r = range(len(digits)-2, -1, -1)
	for i in r:
		d = digits[i]
		num *= 10
		num += d
	
	return num
		
def enumerate_fairs(start_sqr):
	digits = [1]
	repeat_last_digit = False
	
	#try to add_digits:
	while True:
		num = make_num(digits+[0],False)
		if num*num <= start_sqr:
			digits = digits+[0]
		else:
			break
	
	#try to set repeat_last_digit to True:
	num = make_num(digits,True)
	if num*num <= start_sqr:
		repeat_last_digit = True
	
	#try to increase the digits
	for d in range(len(digits)):
		while digits[d]<9:
			digits[d] += 1
			num = make_num(digits,True)
			if not (num*num <= start_sqr):
				digits[d] -= 1
				break
	
	#print "start: %d" % make_num(digits, repeat_last_digit)
	
	while True:
		yield make_num(digits, repeat_last_digit)
		
		index = len(digits)-1
		while index>=0:
			digits[index] += 1
			if digits[index] <= 9:
				break
			
			#next digit
			digits[index] = 0
			index -= 1
		
		if index==-1:
			#we need to add more digit to the number
			if not repeat_last_digit:
				#[9],False  	(9) 	->    [1],True		(11)
				#[99],False  	(999)	->    [10],True		(1001)
				repeat_last_digit = True
				digits = [0]*len(digits)
				digits[0]=1
			else:
				#[9],True  		(99) 	->    [10],False 	(101)
				#[99],True  	(9999)	->    [100],False	(10001)
				repeat_last_digit = False
				digits = [0]*(len(digits)+1)
				digits[0]=1

def is_fair(num):
	digits = []
	while num > 0 :
		digits.append(num%10)
		num /= 10
	
	digits_r = digits[:]
	digits_r.reverse()
	
	return digits == digits_r

def count_fas(start,end):
	count = 0
	for fair in enumerate_fairs(start):
		sqr_fair = fair*fair
		if sqr_fair>end:
			return count
		if sqr_fair<start:
			continue
		if is_fair(sqr_fair):
			#print fair,sqr_fair
			count += 1

def read_numbers():
	return map(int, raw_input().split(" "))
	
cases_count = input()
for case in xrange(cases_count):
	start,end = read_numbers()
	
	count = count_fas(start,end)
	
	print "Case #%d: %d" % (case+1, count)
