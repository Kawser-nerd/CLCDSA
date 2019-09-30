N = int(input())
S = []
for i in range(N):
	S.append(list(input())[0])

count = [0] * 5
for i in range(N):
	if S[i] == "M":
		count[0] += 1
	elif S[i] == "A":
		count[1] += 1
	elif S[i] == "R":
		count[2] += 1
	elif S[i] == "C":
		count[3] += 1
	elif S[i] == "H":
		count[4] += 1
		
sum = 0
for i in range(3):
	sum += count[i] * count[i+1] * count[i+2]

for i in range(2):
	sum += count[i] * count[i+1] * count[i+3]
	sum += count[i] * count[i+2] * count[i+3]

for i in range(3):
		sum += count[0] * count[i+1] * count[4]
print(sum)