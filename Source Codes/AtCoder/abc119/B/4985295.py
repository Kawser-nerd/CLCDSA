import sys

n = int(input())
money = 0
for i in range(n):
	y = sys.stdin.readline().rstrip('\n')
	a,b = y.split(' ')
	x = float(a)
	if b == 'JPY':
		money = money + x
	else:
		money = money + x * 380000.0

print(money)