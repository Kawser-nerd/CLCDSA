
import sys



if __name__ == "__main__":
    ifi = file(sys.argv[1], 'r')
    line = ifi.readline()
    Tests = int(line)
    for test in xrange(0, Tests):
        print "Case #%d:" % (test+1),
        line = ifi.readline()
        N = int(line)
        line = ifi.readline()
        vec1 = map(int, line.strip().split(" "))
        line = ifi.readline()
        vec2 = map(int, line.strip().split(" "))
        vec1.sort()
        vec2.sort(reverse=True)
        sum = 0
        for k in xrange(0, N):
            sum += vec1[k] * vec2[k]

        print sum



