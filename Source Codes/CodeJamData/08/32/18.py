P = [2,3,5,7]
COUNTER = 0
def isUgly(arr):
	num = 0
	for i in arr:
		num += int(i)

	if num == 0 or num % 2 == 0 or num % 3 == 0 or num % 5 == 0 or num % 7 == 0 :
		return True
	return False

def evaluate(str, arr, c):
	global COUNTER
	if len(str) == 1 :
		arr = [str+c] + arr
		if isUgly(arr):
			COUNTER = COUNTER + 1
		return
	n=str[-1]
	next = str[:-1]
	evaluate(next, arr+[n+c], "")
	evaluate(next, arr+["-"+n+c], "")
	evaluate(next, arr, n+c)

def isAllFiveOrZero(case):
	for i in case:
		if not (i == "5" or i == "0"):
			return False
	return True

def isAllEven(case):
	for i in case:
		if not (i == "2" or i == "0" or i == "4" or i == "6" or i == "8"):
			return False
	return True

def isAllThrees(case):
	for i in case:
		if not (i == "3" or i == "0" or i == "6" or i == "9"):
			return False
	return True

def isAllSevens(case):
	for i in case:
		if not (i == "7" or i == "0"):
			return False
	return True

def calculateAllCase(n):
	return 3 ** (n - 1)

def main():
	global COUNTER
	import sys
	for i in range(1, int(sys.stdin.readline())+1):
		input = sys.stdin.readline().strip()
		for j, c in enumerate(input):
			if not c=="0":
				break
		case = input[j:]
		COUNTER = 0
		if len(case) == 0 or isAllFiveOrZero(case) or isAllEven(case) or isAllThrees(case) or isAllSevens(case):
			COUNTER = calculateAllCase(len(case))
		else:
			evaluate(case, [], "")

		if j > 0 :
			COUNTER *= 3 ** j
		print j, COUNTER
		print "Case #" + str(i) + ": "+ str(COUNTER)
		sys.stderr.write(str(i)+"\r\n")

if __name__ == "__main__" : main()
