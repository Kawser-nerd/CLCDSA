#!/usr/bin/python

def compute_rpis(n, matrix):
    wins = []
    losses = []
    opponents = []
    wps = []
    for i in range(n):
        win = 0
        lose = 0
        for j in range(n):
            if j == i:
                continue
            if matrix[i][j] == '1':
                win += 1
            elif matrix[i][j] == '0':
                lose += 1
        wins.append(win)
        losses.append(lose)
        opponents.append(win + lose)
        wps.append(1.0 * win / (win + lose))
    # print "wps:", wps

    owps = []
    for i in range(n):
        sum = 0.0
        for j in range(n):
            if matrix[i][j] == '.':
                continue
            if matrix[i][j] == '1': # opponent lost
                adj_wp = 1.0 * wins[j] / (opponents[j] - 1)
            else: # opponent won
                adj_wp = 1.0 * (wins[j] - 1) / (opponents[j] - 1)
            # print "for i=%d j=%d, adj_wp=%f" % (i, j, adj_wp)
            sum += adj_wp
        owps.append(sum / opponents[i])
    # print "owps:", owps

    oowps = []
    for i in range(n):
        sum = 0.0
        for j in range(n):
            if matrix[i][j] == '.':
                continue
            sum += owps[j]
        oowps.append(sum / opponents[i])

    rpis = []
    for i in range(n):
        rpi = 0.25 * wps[i] + 0.5 * owps[i] + 0.25 * oowps[i]
        rpis.append(rpi)
    return rpis


if __name__ == "__main__":
    import sys
    tests = int(sys.stdin.readline())
    for t in range(tests):
        n = int(sys.stdin.readline())
        matrix = []
        for i in range(n):
            s = sys.stdin.readline().rstrip()
            assert len(s) == n
            matrix.append(s)
        rpis = compute_rpis(n, matrix)
        print "Case #%d:" % (t + 1)
        print "\n".join("%s" % rpi for rpi in rpis)


