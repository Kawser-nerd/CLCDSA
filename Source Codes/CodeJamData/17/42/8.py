numInputs = int(input())

for i in range(numInputs):
	N, C, M = [int(num) for num in input().split(" ")]
	custSeats = [{}, {}]
	seatsBought = set()
	for _ in range(M):
		seatNum, custNum = [int(num) for num in input().split(" ")]
		seatsBought.add(seatNum)
		if seatNum in custSeats[custNum - 1].keys():
			custSeats[custNum - 1][seatNum] += 1
		else:
			custSeats[custNum - 1][seatNum] = 1
	numTicketsBought = [0, 0]
	for custNum in range(2):
		for seatNum in custSeats[custNum].keys():
			numTicketsBought[custNum] += custSeats[custNum][seatNum]
	larger = max(numTicketsBought)
	smaller = min(numTicketsBought)
	numRides = larger
	numPromotions = 0
	for seatNum in seatsBought:
		if seatNum not in custSeats[0].keys() or seatNum not in custSeats[1].keys():
			# only one customer bought this seat, so there are no conflicts possible
			continue
		if custSeats[0][seatNum] + custSeats[1][seatNum] <= larger:
			# not enough tickets bought for this seat to really cause any problems
			continue
		if seatNum == 1:
			# can't promote to resolve conflicts, so just have to add more rides
			numRides = custSeats[0][seatNum] + custSeats[1][seatNum]
		else:
			# promote to resolve conflicts
			numPromotions += custSeats[0][seatNum] + custSeats[1][seatNum] - larger
	print("Case #" + str(i + 1) + ": " + str(numRides) + " " + str(numPromotions))

	