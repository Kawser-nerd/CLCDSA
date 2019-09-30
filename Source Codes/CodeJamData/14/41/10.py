from sys import stdin

T = int(stdin.readline())
for t in range(1,T+1):
    N, X = [int(word) for word in stdin.readline().strip().split()]

    S = sorted([int(word) for word in stdin.readline().strip().split()])

    y0 = 0; y1 = N//2 + 1

    while y1 - y0 > 1:
        y = (y1+y0)//2
        if all([ S[i] + S[2*y-1-i] <= X for i in range(y)]):
            y0 = y
        else:
            y1 = y

    print "Case #"+str(t)+":",N-y0
