def puts(s):
	print(s,end='')

vowels = "aeiou"

def solve(case):
	S, n = input().split()
	n = int(n)

	streak = 0
	cons = []
	for c in S:
		if c in vowels:
			streak = 0
		else:
			streak += 1
		cons += [streak]

	count = 0
	m = 0
	for i in range(len(S)):
		if cons[i]>=n:
			m = i+2-n
		count += m

	print(count)

for case in range(1,1+int(input())):
	puts("Case #"+str(case)+": ")
	solve(case)