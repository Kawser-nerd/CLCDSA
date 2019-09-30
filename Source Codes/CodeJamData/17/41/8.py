from math import ceil, floor

numInputs = int(input())

for i in range(numInputs):
	N, P = [int(num) for num in input().split(" ")]
	G = [int(num) for num in input().split(" ")]
	numsMod = {}
	for j in range(P):
		numsMod[j] = 0
	for g in G:
		numsMod[g % P] += 1

	if P == 2:
		print("Case #" + str(i + 1) + ": " + str(numsMod[0] + ceil(numsMod[1] / 2.0)))
		continue

	if P == 3:
		smaller = min(numsMod[1], numsMod[2])
		larger = max(numsMod[1], numsMod[2])
		diff = larger - smaller
		print("Case #" + str(i + 1) + ": " + str(numsMod[0] + smaller + ceil(diff / 3.0)))
		continue

	# otherwise, P = 4
	total = numsMod[0]
	total += floor(numsMod[2] / 2.0)
	smaller = min(numsMod[1], numsMod[3])
	larger = max(numsMod[1], numsMod[3])
	diff = larger - smaller
	total += smaller

	if numsMod[2] % 2 == 1:
		total += 1
		if diff > 2:
			total += ceil((diff - 2) / 4.0)
	else:
		total += ceil(diff / 4.0)
	print("Case #" + str(i + 1) + ": " + str(total))
	