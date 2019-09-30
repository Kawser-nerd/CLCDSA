import sys

f = open(sys.argv[1], 'r')
T = int(f.readline())
for case in range(0, T):
    line = [int(x) for x in f.readline().split()]
    (N, S) = line[0], line[1:]

    state = {}
    for given in S:
        state[given] = set([given])   

    def compute():
        for n in range(1, N):
            items = state.items()
            for i in range(0, len(items) - 1):
                for j in range(i + 1, len(items)):
                    bag_i, bag_j = items[i][1], items[j][1]
                    bag_new = bag_i | bag_j
                    sum_new = sum(bag_new)
                    if sum_new in state:
                        if bag_new != state[sum_new]:
                            return (bag_new, state[sum_new])
                    else:
                        state[sum_new] = bag_new
        return None

    ret = compute()
    print "Case #%d:" % (case + 1)
    if ret == None:
        print "Impossible"
    else:
        (bag_a, bag_b) = ret
        print " ".join([str(x) for x in bag_a])
        print " ".join([str(x) for x in bag_b])
