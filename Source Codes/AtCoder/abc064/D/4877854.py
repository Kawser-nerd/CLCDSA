N = int(input())

S = input()
while True:
	nl = 0
	nr = 0
	j = "O"
	for i in S:
		if i == "(":
			nl += 1
		else:
			nr += 1
		if nr > nl:
			S = "(" + S
			j = "N"
			break
	if j == "O":
		break

n = S.count("(") - S.count(")")
print(S + n * ")")