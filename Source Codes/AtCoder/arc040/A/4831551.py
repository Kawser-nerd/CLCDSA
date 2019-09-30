n = int(input())
R = 0
B = 0
for i in range(n):
	s = input()
	R += s.count('R')
	B += s.count('B')
if R > B:
	print('TAKAHASHI')
elif R == B:
	print("DRAW")
else:
	print("AOKI")