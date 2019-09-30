def speed(speeds):
    table = [1]
    for i in range(1,len(speeds)):
        table.append(1)
        for j in range(0,i):
            if speeds[i] > speeds[j]:
                table[i] += table[j]
    return sum(table) % 1000000007
        


def generate_speeds(A,n,m,X,Y,Z):
    B = []
    for i in range(0,n):
        B.append(A[i%m])
        #print A[i % m]
        A[i % m] = (X * A[i % m] + Y * (i + 1)) % Z
    return B


N = int(raw_input())
for i in range(1,N+1):
    a = []
    n,m,x,y,z = map(int,raw_input().split())
    for j in range(0,m):
        a.append(int(raw_input()))
    print "Case #%d: %d" % (i,speed(generate_speeds(a,n,m,x,y,z)))
