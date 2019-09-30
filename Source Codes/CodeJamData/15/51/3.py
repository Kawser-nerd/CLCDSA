import sys



def run(N,D,S0, As, Cs, Rs,M0, Am, Cm, Rm):
    # generate the guys
    sal = [S0]
    man_ = [M0]
    for i in range(1,N):
        sal.append((sal[-1]*As+Cs) % Rs)
        man_.append((man_[-1]*Am+Cm) % Rm)
    man = [-1] + [man_[i] % i for i in range(1,N)]

    # compute ranges
    ranl = [sal[0]-D]
    ranh = [sal[0]]
    for i in range(1,N):
        sall = Rs+1
        salh = -1
        node = i
        while node != 0:
            sall = min(sall, sal[node])
            salh = max(salh, sal[node])
            node = man[node]
        if (salh - sall <= D):
            ranl.append(salh-D)
            ranh.append(sall)
        # these ranges are inclusive

    ranl.append(Rs+1)
    ranh.append(Rs+1)
    ranl.sort(reverse = True)
    ranh.sort(reverse = True)
    count = 0
    maxx = 0
    for i in range(2*len(ranl)-2):
        if ranl[-1] <= ranh[-1]:
            val = ranl[-1]
            count += 1
            del ranl[-1]
        else:
            val = ranh[-1]
            count -= 1
            del ranh[-1]
        if sal[0]-D <= val and val <= sal[0]:
            if count > maxx:
                maxx = count
        if val > sal[0]:
            break
    return maxx

fin = open(sys.argv[1])

T = int(fin.readline().strip())
for i in range(1,T+1):
    N,D = [int(x) for x in fin.readline().strip().split()]
    S0, As, Cs, Rs = [int(x) for x in fin.readline().strip().split()]
    M0, Am, Cm, Rm = [int(x) for x in fin.readline().strip().split()]
    ans = run(N,D,S0, As, Cs, Rs,M0, Am, Cm, Rm)
    print('Case #%d: %s' % (i, ans))
