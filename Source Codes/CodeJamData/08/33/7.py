import sys

for case in range(1, int(sys.stdin.readline())+1):
    (n, m, X, Y, Z) =  map(int, sys.stdin.readline().split(' '))
    A=[]
    for i in range(m):
        A.append(int(sys.stdin.readline()))
    L=[]
    S=[]
    for i in range(n):
        L.append(A[i % m])
        S.append(0)
        A[i % m] = (X * A[i % m] + Y * (i + 1)) % Z
    S[-1] = 1
    sum = 1
    for i in range(len(L)-2, -1, -1):
        cnt = 1
        for j in range(i+1, len(L)):
            if(L[j] > L[i]):
                cnt += S[j] % 1000000007
        S[i] = cnt
        sum = (sum + cnt) % 1000000007
#    print L
#    print S
    print "Case #%d: %d" % (case, sum)
        