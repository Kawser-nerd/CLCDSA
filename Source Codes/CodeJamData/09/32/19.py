import sys, decimal

with open(sys.argv[1]) as f:
    for n in range(int(f.readline().strip())):
        flies = []
        for N in range(int(f.readline().strip())):
            flies.append([decimal.Decimal(x) for x in f.readline().strip().split()])

        com = [0 for x in range(6)]
        for i in range(6):
            for fly in flies:
                com[i]+=fly[i]
            com[i] /= N+1
#       print(com)
        s, t = 0, 0
        for i in range(3):
            s += com[3+i]*com[i] 
            t += com[3+i] ** 2
#        print(com,s,t)
        if t == 0:
            dist = ((com[0])**2+(com[1])**2+(com[2])**2)**decimal.Decimal("0.5")
            time = 0.0
            print("Case #",str(n+1),": ","{0:.8f}".format(dist)," ","{0:.8f}".format(time),sep="")
            continue
        T = -s/t
        if T < 0:
            dist = ((com[0])**2+(com[1])**2+(com[2])**2)**decimal.Decimal("0.5")
            time = 0.0
            print("Case #",str(n+1),": ","{0:.8f}".format(dist)," ","{0:.8f}".format(time),sep="")
            continue
            
        F = [com[0]+T*com[3],com[1]+T*com[4],com[2]+T*com[5]]
#        print(F)
        dist = (F[0]**2+F[1]**2+F[2]**2)**decimal.Decimal("0.5")
        time = (((F[0]-com[0])**2+(F[1]-com[1])**2+(F[2]-com[2])**2)**decimal.Decimal("0.5"))/(com[3]**2+com[4]**2+com[5]**2)**decimal.Decimal("0.5")
        print("Case #",str(n+1),": ","{0:.8f}".format(dist)," ","{0:.8f}".format(time),sep="")
