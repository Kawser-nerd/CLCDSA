

f_in = open("../Downloads/B-large-1.in")
cases = int(f_in.readline().rstrip())
#print cases
for test_case in range(cases):
	N = int(f_in.readline().rstrip())
	#print N
	flavours = [0]*N
	M = int(f_in.readline().rstrip())
	#print M
	customers = []
	for ii in range(M):
		customers.append(f_in.readline().rstrip().split(" "))
		if not (2*int(customers[ii][0])+1 == len(customers[ii])):
			print "*** NOT EQUAL LENS ***"
		for jj in range(len(customers[ii])):
			customers[ii][jj] = int(customers[ii][jj])
	
	change_made = True
	output = ""
	while change_made == True:
		change_made = False
		for customer in customers:
			happy = False
			for ii in range(customer[0]):
				#print ii,N,M,len(customer), customer[0], customer[2*ii + 1]
				if customer[2*ii + 2] == flavours[customer[2*ii + 1]-1]:
					happy = True
					break
			if not happy:
				change_made = True
				made_happy = False
				for ii in range(customer[0]):
					if customer[2*ii + 2] == 1:
						made_happy = True
						flavours[customer[2*ii+1]-1] = 1
						break
				if not made_happy:
					output = "IMPOSSIBLE"
					break
		if output == "IMPOSSIBLE":
			break
				
	if output == "IMPOSSIBLE":
		print "Case #%d: %s" %(test_case + 1, output),
	else:
		print "Case #%d:" %(test_case + 1),
		for ii in range(N):
			print flavours[ii],
	print
					
	
