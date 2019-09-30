f = open("data.txt", 'r')
g = open("data1.txt", 'w')

line = f.readline()
t = int(line)
for i in range(1, t+1):
    line = f.readline()
    (n, w, l) = (int(x) for x in line.split())
    line = f.readline()
    radii = [int(x) for x in line.split()]
    points = []
    y = 0
    j = 0
    check = 0
    while j < n:
        points.append([0, y])
        j+=1
        while True:
            if j == n:
                break
            if radii[j-1] + points[-1][0] + radii[j] > w:
                y = y + max(radii[check:j]) + max(radii[j:])
                check = j
                break
            else:
                points.append([radii[j-1] + points[-1][0] + radii[j], y])
                j+=1
                
    result = ""
    for u in points:
        result += str(u[0])
        result += " "
        result += str(u[1])
        result += " "
    string = "Case #" + str(i) + ": " + result + '\n'
    g.write(string)

f.close()
g.close()
