import math

result = []

tt7 = 10000000
tt25 = 10000000000000000000000000L

#MAX = tt7 * tt7
MAX = tt25 * tt25 * tt25 * tt25 * 10

result.append(1)
result.append(4)
result.append(9)

def process(num):
	if len(num) == 0:
		return True
	ixx = int(num)
	sq = ixx * ixx
	palin = str(sq)
	if palin == palin[::-1] and sq >= 10:
		result.append(sq)
		return True
	elif sq < 10:
		return True
	return False

def dfs(num):
	yes = process(num)
	if yes == False:
		return
	#print "--", num
	x = '1'
	while True:
		xx = x + num + x[::-1]
		ixx = int(xx)
		if ixx * ixx > MAX:
			break
		dfs(x + num + x[::-1])
		x += '0'
	x = '2'
	while True:
		xx = x + num + x[::-1]
		ixx = int(xx)
		if ixx * ixx > MAX:
			break
		dfs(x + num + x[::-1])
		x += '0'




dfs('')
dfs('0')
dfs('1')
dfs('2')

result = sorted(result)
#print MAX
#print len(result)
#for i in result:
#	print i

test = input()
for cases in range(1, test + 1):
	cnt = 0
	a, b = map(int, raw_input().split())
	for x in range(len(result)):
		if result[x] >= a and result[x] <= b:
			cnt += 1
		elif result[x] > b:
			break
	print "Case #" + str(cases) + ": " + str(cnt)

