#f = file("test1.in", "r")
#f = file("/Users/finn/Downloads/A-small-attempt0.in", "r")
#f = file("/Users/finn/Downloads/A-small-attempt1.in", "r")
#f = file("/Users/finn/Downloads/A-small-attempt2.in", "r")
f = file("/Users/finn/Downloads/A-large.in", "r")
#of = file("A-small.out", "w")
of = file("A-large.out", "w")
lines = f.readlines()

cases = int(lines[0])
line = 1
for case in range(cases):
	n = int(lines[line])
	line += 1
	
	wires = []
	
	for a in range(n):
		w = lines[line].split(" ")
		wires.append((int(w[0]), int(w[1])))
		line += 1
		
	print wires
	
	total = 0
	for i in range(len(wires)):
		j = i + 1
		while j < len(wires):
			if wires[i][0] < wires[j][0] and wires[i][1] > wires[j][1]:
				total += 1
			if wires[i][0] > wires[j][0] and wires[i][1] < wires[j][1]:
				total += 1
				
			j += 1
		
		i += 1		
	
	print "cross", total
	of.write("Case #%d: %d\n" % (case + 1, total))