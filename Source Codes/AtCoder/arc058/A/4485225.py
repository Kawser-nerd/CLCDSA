import sys
sys.setrecursionlimit(10**6)

def main():
	n, k = map(int, input().split())
	lst = list(input().split())
	for i in range(n, 1000000):
		flg = True
		for j in str(i):
			if j in lst:
				flg = False
		if flg:
			print(i)
			return

main()