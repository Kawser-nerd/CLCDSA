# memoize decorator
# Reference: http://avinashv.net/2008/04/python-decorators-syntactic-sugar/
class memoize:
  def __init__(self, function):
    self.function = function
    self.memoized = {}

  def __call__(self, *args):
    try:
      return self.memoized[args]
    except KeyError:
      self.memoized[args] = self.function(*args)
      return self.memoized[args]

#@memoize
def dist(w, minI):
	if w in D:
		return 0,
	for i in xrange(minI, len(w)):
		for c1 in 'abcdefghijklmnopqrstuvwxyz':
			ca = list(w)
			ca[i] = c1
			_w = ''.join(ca)
			if _w in D:
				return 1, i
	for j in xrange(len(w)):
		for c2 in 'abcdefghijklmnopqrstuvwxyz':	
			if j-5<minI: continue
			for i in xrange(j-5, -1, -1):
				for c1 in 'abcdefghijklmnopqrstuvwxyz':
					ca = list(w)
					ca[i] = c1
					ca[j] = c2
					_w = ''.join(ca)
					if _w in D:
						return 2, i, j
	return 3, -1

def _minChange(sIdx, pModIdx):
	if sIdx == N:
		return 0
	r = N
	for eIdx in xrange(sIdx, min(sIdx+10,N)):
		w = S[sIdx:(eIdx+1)]
		d = dist(w, max(0, 5 - (sIdx - pModIdx)))
		if d[0] == 0:
			r = min(r, minChange(eIdx + 1, pModIdx))
		if d[0] == 1 and (sIdx + d[1] - pModIdx) >= 5:
			r = min(r, minChange(eIdx + 1, sIdx + d[1]) + 1)
		if d[0] == 2 and (sIdx + d[1] - pModIdx) >= 5:
			r = min(r, minChange(eIdx + 1, sIdx + d[2]) + 2)
	return r

dict_file = 'garbled_email_dictionary.txt'
with open(dict_file, 'r') as fp:
	D = set([w.strip() for w in fp.readlines()])
#print max(map(len, D));import sys;sys.exit(0)
T = input()
for case_no in range(1, T+1):
	S = raw_input()
	N = len(S)
	minChange = memoize(_minChange)
	r = minChange(0, -5)
	if r == N and r>1:
		print 'Error'
	print 'Case #%i: %i' % (case_no, r)