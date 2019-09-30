


with open('input.in', 'r') as fin:
    with open('output.txt', 'w') as fout:
        numcases = int(fin.readline())
        for casenum in range(1, numcases+1):
            info = [int(i) for i in fin.readline().split()]
            length = info[0]
            walksp = float(info[1])
            runsp = float(info[2])
            runt = float(info[3])
            walkways = []
            for walkway in range(info[4]):
                w = [int(i) for i in fin.readline().split()]
                walkways.append((w[2], (w[1]-w[0])))
            walkways.sort()
            lengths = sum([x[1] for x in walkways])
            time = 0.0
            nowalklen = length - lengths
            print(nowalklen)
            if (runt < nowalklen/runsp):
                time = runt + (nowalklen-(runsp*runt))/walksp
                runt = 0
            else:
                runt -= nowalklen/runsp
                time += nowalklen/runsp
            print(time)
            for i in walkways:
                if (runt < i[1]/(i[0]+runsp)):
                    time += runt + (i[1]-((i[0]+runsp)*runt))/(i[0]+walksp)
                    runt = 0
                else:
                    time += i[1]/(i[0]+runsp)
                    runt -= i[1]/(i[0]+runsp)
                    













            fout.write("Case #"+str(casenum)+": "+str(time)+'\n')
