import sys
sys.setrecursionlimit(10**6)

def main(n):
	a = list(map(int, input().split()))
	ans = 10**8
	for i in range(-100, 101, 1):
		temp = 0
		for j in a:
			temp += (i-j)**2
		if ans > temp:
			ans = temp
	print(ans)

main(int(input()))