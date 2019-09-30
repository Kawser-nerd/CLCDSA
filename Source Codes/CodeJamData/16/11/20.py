import sys
import itertools

def ans(S):
	ans = ""
	for x in S:
		if (x+ans) > (ans+x):
			ans = x+ans
		else:
			ans = ans+x
	return ans

def main():
	s = sys.stdin.readline()
	T = int(s)
	for i in xrange(0,T):
		S = sys.stdin.readline()
		print "Case #{0}: {1}".format(i+1, ans(S.strip()))

if __name__ == "__main__":
	main()
