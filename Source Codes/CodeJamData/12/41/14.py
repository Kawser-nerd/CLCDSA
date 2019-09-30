f = open("data.txt", 'r')
g = open("data1.txt", 'w')

line = f.readline()
t = int(line)
for i in range(1, t+1):
    line = f.readline()
    n = int(line)
    vines = []
    for j in range(n):
        line = f.readline()
        integers = [int(x) for x in line.split()]
        vines.append(integers)
    line = f.readline()
    d = int(line)
    vines.append([d, 0])
    reachable = dict()
    reachable[0] = vines[0][0]
    for j in range(1, n+1):
        reachable[j] = -1
    for j in range(n):
        hook = vines[j][0]
        hang = reachable[j]
        for k in range(j+1, n+1):
            if (vines[k][0] - hook) > hang:
                break
            reachable[k] = max(reachable[k], min(vines[k][1], (vines[k][0] - hook)))
    if reachable[n] > -1:
        result = "YES"
    else:
        result = "NO"
    string = "Case #" + str(i) + ": " + result + '\n'
    g.write(string)

f.close()
g.close()
