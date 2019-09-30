inp = open("d:\\incoming\\a-large (1).in", "r")
#inp = open("d:\\incoming\\a-small-attempt0.in", "r")
#inp = open("d:\\incoming\\a.in", "r")
outp = open(".\\a.out", "w")

T = int(inp.readline())
for cc in range(T):
    sol = -1
    n = int(inp.readline())
    seq = []
    for i in range(n):
        line = inp.readline().strip()
        if "1" in line:
            seq.append(line.rindex("1"))
        else:
            seq.append(-1)

    sol = 0
    for i in range(n):
        j = i
        while seq[j] > i:        
            j += 1
        sol += (j - i)
        seq = seq[:i] + seq[j:j+1] + seq[i:j] + seq[j+1:]
    
    outp.write("Case #%d: %d\n" % (cc+1, sol))
    print "Case #%d: %d" % (cc+1, sol)
   
outp.close()
