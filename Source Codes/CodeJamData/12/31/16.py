import sys


_in = sys.stdin
#_out = sys.stdout


T = int(_in.readline())

for ci in range(T):
    N = int(_in.readline())
    g = [None]*N
    for i in range(N):
        g[i] = list(map(int,_in.readline().split()))

    ck = set()

    solved = False

    for i in range(N):
        cg = set()
        cl = []
        if i+1 not in ck:
            ck.add(i+1)
            cg.add(i+1)
            cl.append(i+1)

            while cl and not solved:
                c = cl.pop(0)
                if g[c-1][0] != 0:
                    for j in g[c-1][1:]:
                        if j in cg:
                            solved = True
                            break
                        else:
                            ck.add(j)
                            cg.add(j)
                            cl.append(j)

            if solved:
                break
                            
                        


    print("Case #{}:".format(ci+1),end=' ')
    if solved:
        print("Yes")
    else:
        print("No")
