f_in = open('file.in')
f_out = open('file.out','w')

cases = int(f_in.readline())
for i in range(1,cases+1):
	shynesses = f_in.readline().split()[1]
	shynesses = [int(i) for i in list(shynesses)]
	friends = 0
	current = 0
	for j in range(0, len(shynesses)):
	    if current < j and shynesses[j] != 0:
	        friends += j-current
	        current += j-current
	    current += shynesses[j]
	f_out.write("Case #"+str(i)+": "+str(friends)+"\n")