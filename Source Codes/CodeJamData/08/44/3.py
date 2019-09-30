import psyco
def main():
	kk = {}
	kk[1] = [[1]]
	kk[2] = [[1,2],[2,1]]
	kk[3] = []
	for t in kk[2]:
		for u in xrange(len(t)+1):
			tt = t[:]
			tt.insert(u, 3)
			kk[3].append(tt)
	kk[4] = []
	for t in kk[3]:
		for u in xrange(len(t)+1):
			tt = t[:]
			tt.insert(u, 4)
			kk[4].append(tt)
	kk[5] = []
	for t in kk[4]:
		for u in xrange(len(t)+1):
			tt = t[:]
			tt.insert(u, 5)
			kk[5].append(tt)

	tn = input()
	for loop in xrange(1, tn+1):
		print 'Case #%d:' % loop,
		k = input()
		s = raw_input()
		mchc = len(s)
		for t in kk[k]:
			lastch = '_'
			for sindex in xrange(0,len(s),k):
				ss = s[sindex:sindex+k]
				for u in t:
					ch = ss[u-1]
					if lastch[-1] != ch:
						lastch += ch
			chc = len(lastch)-1
			if mchc > chc:
				mchc = chc
		print mchc

psyco.full()
main()
