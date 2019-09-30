fin = open('A-large.in', 'r')
fout = open('out.txt', 'w')
t = int(fin.readline())
for casecount in range(1, t + 1):
    n, l = map(int, fin.readline().split())
    outlet = [list(x) for x in fin.readline().split()]
    device = [list(x) for x in fin.readline().split()]
    device.sort()
    #print(outlet, device)
    smallest = 41
    for func in range(0, n):
        switch = []
        for i in range(0, l):
            if outlet[0][i] != device[func][i]:
                switch.append(i)
        output = []
        for x in outlet:
            x1 = x.copy()
            for y in switch:
                if x1[y] == '0':
                    x1[y] = '1'
                else:
                    x1[y] = '0'
            output.append(x1)
        output.sort()
        if smallest > len(switch) and output == device:
            smallest = len(switch)
    fout.write('Case #%d: ' % casecount)
    if smallest == 41:
        fout.write('NOT POSSIBLE\n')
    else:
        fout.write('%d\n' % smallest)
fin.close()
fout.close()
