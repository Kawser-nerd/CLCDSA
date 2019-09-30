inp = open("d:\\incoming\\d-small-attempt0.in", "r")
#inp = open("d:\\incoming\\d.in", "r")
outp = open(".\\d.out", "w")

def go(plants, a, b, c):
    from math import hypot
    return max(plants[a][2], (hypot(plants[b][0] - plants[c][0], plants[b][1] - plants[c][1]) + plants[b][2] + plants[c][2]) / 2.0)
   

T = int(inp.readline())
for cc in range(T):
    n = int(inp.readline())
    plants = []
    for i in range(n):
        plants.append(tuple(map(int,inp.readline().split())))
    if n == 1:
        sol = plants[0][2]
    elif n == 2:
        sol = max(plants[0][2], plants[1][2])
    else:
        sol = 1e20
        sol = min(sol, go(plants, 0, 1, 2))
        sol = min(sol, go(plants, 1, 0, 2))
        sol = min(sol, go(plants, 2, 0, 1))
    outp.write("Case #%d: %.10lf\n" % (cc+1, sol))
    print "Case #%d: %.10lf" % (cc+1, sol)
   
outp.close()
