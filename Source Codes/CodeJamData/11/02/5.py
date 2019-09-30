# axc

f = open('magicka.in', 'r')
def input():
	return f.readline()
fo = open('magicka.out', 'w')

def cancombine(string, lis):
	for i in lis:
		if string in i[:2] or string[::-1] in i[:2]:
			return True
	return False
	
def ccombine(string, lis):
	for i in lis:
		if string in i[:2] or string[::-1] in i[:2]:
			return i[2]
	return ''

def canremove(s, ch, oppose):
	for i in oppose:
		if ch == i[0] and i[1] in s: return True
		if ch == i[1] and i[0] in s: return True
	return False

def remove(s, ch):
	t = ''
	for i in s:
		if i != ch: t += i
	return t

t = int(input())
for i in range(1, t + 1):
	combine = []
	oppose = []
	line = input().strip('\n').split(' ')
	pos = 0
	c = int(line[pos])
	pos += 1
	for j in range(pos, pos + c):
		combine.append(line[j])
	pos += c
	d = int(line[pos])
	pos += 1
	for j in range(pos, pos + d):
		oppose.append(line[j])
	pos += d
	l = int(line[pos])
	pos += 1
	s = line[pos]
	answer = ''
	print i
	for n in s:
		answer += n
		print answer
		while len(answer) >= 2 and cancombine(answer[-2:], combine):
			print 'remove!'
			answer = answer[:-2] + ccombine(answer[-2:], combine)
			print answer
		# remove stuff
		while len(answer) >= 2 and canremove(answer, answer[-1], oppose):
			print 'clear!'
			answer = ''
	fo.write('Case #' + str(i) + ': ' + remove(str(list(answer)), "'") + '\n')

fo.close()