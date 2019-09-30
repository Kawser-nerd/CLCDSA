# Google Code Jam : Round 1C 2011 : Problem B. Space Emergency
# https://code.google.com/codejam/contest/dashboard?c=1128486#s=p1
# Python 2.6.5

def solve_case(t, L, t_booster, stars):
    N = len(stars)


    for_booster = {}
    t_temp = 0
    for i in xrange(1, N + 1):
        if t_temp >= t_booster:
            for_booster[i] = stars[i]
        else:
            if t_temp + stars[i] * 2 <= t_booster:
                for_booster[i] = 0
            else:
                for_booster[i] = stars[i] - (t_booster - t_temp) / 2
            t_temp += stars[i] * 2

        stars[i] *= 2

    k = for_booster.keys()
    k.sort(key=for_booster.__getitem__, reverse=True)
    for i in xrange(L):
        m = k[i]
        stars[m] -= for_booster[m]
 
    time = 0
    for i in xrange(1, N + 1):
        time += stars[i]

    print "Case #" + str(t) + ": " + str(time)


def solve():
    T = int(raw_input())
    for t in range(1, T + 1):
        s = raw_input().split()
        L = int(s[0])
        t_booster = int(s[1])
        N = int(s[2])
        C = int(s[3])

        s = s[4:]
        s = [int(i) for i in s]

        stars = {}
        for i in range(N):
            stars[i + 1] = s[i % C]

        solve_case(t, L, t_booster, stars)

solve()
