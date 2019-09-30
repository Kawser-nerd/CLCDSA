
def rotations(x):
    s = str(x)
    rots = [int(s[i:]+s[:i]) for i in range(1,len(s))]
    rots = [y for y in rots if y>x]
    return set(rots)

R = [[]] * 2000001

for i in xrange(1,2000001):
    R[i] = rotations(i)

T = input()
for t in range(1,T+1):
    [A, B] = [int(s) for s in raw_input().split()]

    answer = 0
    for i in xrange(A,B):
        for j in R[i]:
            if j <= B:
                answer += 1

    print "Case #" + str(t) + ": " + str(answer)
