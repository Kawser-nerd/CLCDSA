infile = open("A-large.in", "r")
T = int(infile.readline().strip())

for t in range(T):
    wires = []
    total = 0
    N = int(infile.readline().strip())
    for i in range(N):
        wire = eval("("+infile.readline().strip().replace(" ",",")+")")
        for otherwire in wires:
            if (otherwire[0] < wire[0] and otherwire[1] > wire[1]) or (otherwire[0] > wire[0] and otherwire[1] < wire[1]):
                total += 1;
        wires.append(wire);
    print "Case #" + str(t + 1) + ": " + str(total)
