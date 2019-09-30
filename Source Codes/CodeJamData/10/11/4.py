import sys
dx = [1,0,1,1]
dy = [0,1,1,-1]

def check(B,color,K):
    for i in range(len(B)):
        for j in range(len(B)):
            for d in range(4):
                found = True
                for k in range(K):
                    ni = i+k*dx[d]
                    nj = j+k*dy[d]
                    if ni < 0 or nj < 0 or ni >= len(B) or nj >= len(B) or B[ni][nj] != color:
                        found = False
                        break
                if found:
                    return True
                    
    return False

T = int(sys.stdin.readline())
for t in range(T):
    s = sys.stdin.readline().split()
    N = int(s[0])
    K = int(s[1])
    B = []
    for i in range(N):
        l = []
        s = sys.stdin.readline()
        for j in range(N):
            if s[j] == 'R':
                l.append(1)
            elif s[j] == 'B':
                l.append(2)
            else:
                l.append(0)
        B.append(l)
    C = []
    for i in range(N):
        l = []
        for j in range(N):
            l.append(B[N-j-1][i])
        C.append(l)
    update = True
    while update:
        update = False
        for i in range(N):
            for j in range(N):
                if i < N-1 and C[i][j] != 0 and C[i+1][j] == 0:
                    C[i][j],C[i+1][j] = C[i+1][j],C[i][j]
                    update = True
    rwin = check(C,1,K)
    bwin = check(C,2,K)
    if rwin == False and bwin == False:
        print "Case #%d: %s"%(t+1,"Neither")
    elif rwin == True and bwin == False:
        print "Case #%d: %s"%(t+1,"Red")
    elif rwin == False and bwin == True:
        print "Case #%d: %s"%(t+1,"Blue")
    elif rwin == True and bwin == True:
        print "Case #%d: %s"%(t+1,"Both")
                    