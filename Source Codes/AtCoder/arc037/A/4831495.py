n = int(input())
S = list(map(int,input().split()))
t = 0
for s in S:
	if s < 80:
		t += 80-s
print(t)