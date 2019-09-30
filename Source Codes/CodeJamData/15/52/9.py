import sys


def run(N, K, sums):
    diffs = []
    for i in range(K):
        cmin = 0
        cmax = 0
        ctemp = 0
        for j in range(i, N-K, K):
            ctemp += sums[j+1]-sums[j]
            cmin = min(cmin, ctemp)
            cmax = max(cmax, ctemp)
        diffs.append([cmax - cmin, cmin, cmax])
    diffs.sort()
    diff2 = []
    offset = 0
    for d in diffs:
        if d[1] < diffs[-1][1]:
            offset += diffs[-1][1] - d[1]
            diff2.append([d[0], diffs[-1][1], d[2] + diffs[-1][1]-d[1]])
        else:
            diff2.append(d)

    totminus = sum(r[1]-diff2[-1][1] for r in diff2)
    totplus = sum(diff2[-1][2]-r[2] for r in diff2)
    needplus = (sums[0]-offset) % K
    needminus = (offset-sums[0]) % K
    if totminus >= needminus or totplus >= needplus:
        return diff2[-1][0]
    else:
        return diff2[-1][0]+1

    # if plus1 == 0:
    #     return diffs[-1]
    # return max(diffs[plus1-1]+1, diffs[-1])


fin = open(sys.argv[1])

T = int(fin.readline().strip())
for i in range(1,T+1):
    N,K = [int(x) for x in fin.readline().strip().split()]
    sums = [int(x) for x in fin.readline().strip().split()]
    ans = run(N,K, sums)
    print('Case #%d: %s' % (i, ans))
