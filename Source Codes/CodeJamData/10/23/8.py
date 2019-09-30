import sys

sys.setrecursionlimit(100000)

fin = open("input.txt", "r")
fout = open("output.txt", "w")

N = 510
MOD = 100003

line = [-1]*N
mC = []
for i in xrange(N):
	mC.append( line[:] )

mAns1 = []
for i in xrange(N):
	mAns1.append( line[:] )

def C(n, k):
      	if k > n:
      		return 0
      	if k < 0:
      		return 0	
      	if n < 0:
      		return 0
	if mC[n][k] == -1:
              	if n == k:
              		mC[n][k] = 1
              	elif k == 0:
              		mC[n][k] = 1
              	else:
              		mC[n][k] = (C(n - 1, k - 1) + C(n - 1, k)) % MOD
        return mC[n][k]

def ans1(n, s):
        if mAns1[n][s] == -1:
        	if s >= n:
        		mAns1[n][s] = 0
        	elif s == n - 1:
        		mAns1[n][s] = 1
        	elif s == 1:
        		mAns1[n][s] = 1
        	else:
        		res = 0
        		for s1 in xrange(1, s):
        			res = (res + ans1(s, s1)*C(n - s - 1, s - s1 - 1)) % MOD
                	mAns1[n][s] = res % MOD
        return mAns1[n][s]

def ans(n):
	res = 0
	for s1 in xrange(1, n + 1):
		res += ans1(n, s1)
	return res % MOD

# for i in xrange(1, 501):
#	print "a[%d] = %d" % (i, ans(i))

nt = int(fin.readline().strip())
for t in xrange(nt):
	n = int(fin.readline().strip())
	print >>fout, "Case #%d: %d" % (t + 1, ans(n))
