n = 0
b = 0

used = set([])

counter = 0

def count(n,minnum,b):
	global counter
	for num in range(minnum,n+1):
		rep = []
		nnum = num
		while nnum > 0:
			rep.append(nnum % b)
			nnum = nnum/b
		ok = True
		for i in range(len(rep)):
			if (i,rep[i]) in used:
				ok = False
				break
		if ok:
			for i in range(len(rep)):
				used.add((i,rep[i]))
			
			if n-num  == 0:
				counter = counter + 1
			else:
				count(n-num,num+1,b)

			for i in range(len(rep)):
				used.remove((i,rep[i]))


T = int(raw_input())
for i in range(T):
	[n,b] = map(lambda x: int(x), raw_input().split())
	counter = 0
	used = set([])
	count(n,1,b)
	print("Case #%d: %d"%(i+1,counter))

