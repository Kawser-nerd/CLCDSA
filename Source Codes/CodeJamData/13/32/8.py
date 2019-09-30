import sys

T = int(sys.stdin.readline())
for ca in xrange(1, T+1):
    [X, Y] = [int(v) for v in sys.stdin.readline().split(" ")]
    
    print "Case #%d: " % ca,
    
    if X > 0:
        for i in range(X):
            sys.stdout.write("W"),
            sys.stdout.write("E"),
    else:
        X = -X
        for i in range(X):
            sys.stdout.write("E"),
            sys.stdout.write("W"),
    if Y > 0:
        for i in range(Y):
            sys.stdout.write("S"),
            sys.stdout.write("N"),
    else:
        Y = -Y
        for i in range(Y):
            sys.stdout.write("N"),
            sys.stdout.write("S"),
    print ""

