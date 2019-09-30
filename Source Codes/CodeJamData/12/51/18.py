f = open("data.txt", 'r')
g = open("data1.txt", 'w')

t = int(f.readline())
for i in range(1, t+1):
    n = int(f.readline())
    l = [int(x) for x in (f.readline()).split()]
    p = [int(x) for x in (f.readline()).split()]
    result = 0
    m = []
    for j in range(n):
        m.append([100-p[j], j])
    m.sort()
    result = str(m[0][1])
    for j in range(1, n):
        result = result + " " + str(m[j][1])
    
    string = "Case #" + str(i) + ": " + str(result) + "\n"
    g.write(string)

f.close()
g.close()
    
    
