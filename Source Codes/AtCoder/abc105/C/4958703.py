N=int(input())

s=""

while N != 0:
	r = 0 if N % 2 == 0 else 1
	N = (N - r) // -2
	s = str(r) + s

print(s if  s != "" else "0")