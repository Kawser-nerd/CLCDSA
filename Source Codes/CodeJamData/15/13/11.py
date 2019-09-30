import math


fin = open('C-large.in','r')
fout = open('output.txt','w')
t = int(fin.readline())
for count in range(1, t + 1):
    n = int(fin.readline())
    pts = [[0,0] for i in range(0, n)]
    for i in range(0, n):
        pts[i] = [int(i) for i in fin.readline().split()]
    fout.write('Case #'+str(count) + ':\n')
    for current in range(0, n):
        angle = [(0,0, 0) for i in range(0, n - 1)]
        for i in range(0, n):
            if i == current:
                continue
            xdis = pts[i][0] - pts[current][0]
            ydis = pts[i][1] - pts[current][1]
            answer = math.asin(ydis / math.hypot(xdis, ydis))
            if xdis < 0:
                answer = math.pi - answer;
            if i < current:
                angle[i] = (answer, xdis, ydis)
            else:
                angle[i - 1] = (answer, xdis, ydis)
        angle = sorted(angle)
        tail = 1
        result = n - 1
        if n < 3:
            fout.write('0\n')
            continue
        for head in range(0, n - 1):
            while angle[head][1] * angle[tail][2] - angle[head][2] * angle[tail][1] > 0:
                tail = (tail + 1) % (n - 1)
            if tail > head and result > tail - head - 1:
                result = tail - head - 1
            elif tail <= head and result > tail + n - 1 - head - 1:
                result = tail + n - 1 - head - 1
            if result == 0:
                break
        fout.write(str(result) + '\n')
    print(count)
fin.close()
fout.close()
