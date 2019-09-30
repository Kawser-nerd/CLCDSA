k = int(input())
#n = int(input())

def S(x):
	return sum(list(map(int, list(str(x)))))

def T(x):
	return x / S(x)

n = 1
snuke = [1]
x = 1

while n < k:
	x += 1
	cand = x
	T_min = T(x)
	for d in range(len(str(x))-1):
		if T((x // (10**(d+1)) + 1) * (10**(d+1)) - 1) < T_min:
			T_min = T((x // (10**(d+1)) + 1) * (10**(d+1)) - 1)
			cand = (x // (10**(d+1)) + 1) * (10**(d+1)) - 1
	x = cand
	snuke.append(x)
	n += 1

print(*snuke, sep="\n")