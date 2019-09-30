import bisect

def binum(num):
	number_len = len(bin(num))-2
	f = 2**number_len -1
	return (num^f)+1

N = int(input())
A = list(map(int, input().split()))
A.sort()
cnt = 0

while len(A) > 0:
	k = A.pop()
	if len(A) == 0:
		break
	if int(k) != k:
		continue
	x = binum(k)
	if x > A[-1]:
		continue
	if A[bisect.bisect_left(A,x)] == x:
		A[bisect.bisect_left(A,x)] -= 0.5
		cnt += 1

print(cnt)