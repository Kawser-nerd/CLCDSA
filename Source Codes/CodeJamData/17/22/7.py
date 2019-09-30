import sys
sys.stdin = open('input.txt', 'r')
sys.stdout = open('output.txt', 'w')

T = input()
case = 0
while T > 0:
	T -= 1
	a = map(int, raw_input().split())
	n = a[0]
	b = [a[4], a[6], a[2]]
	a = [a[1], a[3], a[5]]
	output = ''
	for i in range(3):
		a[i] -= b[i]
		if a[i] < 0:
			output = 'IMPOSSIBLE'
	if output == '':
		a = list(sorted(filter(lambda (a, c): a > 0, zip(a, 'RYB')), reverse=False))
		a = map(lambda (i, (x, y)): [x, i, y], enumerate(a))
		a = list(sorted(a, reverse=True))
		while len(a) > 0:
			# print a
			if len(output) == 0 or a[0][2] != output[-1]:
				top = a[0]
				a.pop(0)
			elif len(a) > 1:
				top = a[1]
				a.pop(1)
			else:
				output = 'IMPOSSIBLE'
				break
			output += top[2]
			top[0] -= 1
			if top[0] > 0:
				a.append(top)
				a = list(sorted(a, reverse=True))
		if len(output) > 0 and output[0] == output[-1]:
			output = 'IMPOSSIBLE'
	if output != 'IMPOSSIBLE':
		for cnt, ch, sep in zip(b, 'GVO', 'RYB'):
			if len(output) == 0:
				p = 0
			else:
				p = output.find(sep)
			if p != -1:
				output = output[:p] + (sep + ch) * cnt + output[p:]
			elif cnt > 0:
				output = 'IMPOSSIBLE'
				break
		if len(output) > 0 and output[0] == output[-1]:
			output = 'IMPOSSIBLE'
	case += 1
	print 'Case #%d: ' % case + output
