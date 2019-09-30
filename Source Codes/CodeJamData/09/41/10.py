
def CrazyRows():
    N = int(raw_input())
    m = []
    for i in range(N):
        m.append(raw_input().rfind("1"))
    count = 0
    for i in range(0, N):
        s = 0
        while m[i+s] > i:
            s += 1
        if s:
            count += s
            m[i:i+s+1] = m[i+s:i+s+1] + m[i:i+s]
    print count

#---------------------------------------------------------------

T = int(raw_input())
for testcase in range(T):
    print "Case #%d:" % (testcase+1),
    CrazyRows()
