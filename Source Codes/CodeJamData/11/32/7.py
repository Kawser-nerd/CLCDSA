import sys

t = int(sys.stdin.readline())

def space(L, t, N, C, *a):
    planets = (N) * [0]
    times = []
    for i in range(N):
        planets[i] = a[i%C]
    suma = 0
    for i in planets:
        times.append(suma)
        suma += 2*i
    pt = zip(planets, times)
    improvements = []
    for planet, time in pt:
        if time - t > 0:
            improvements.append(planet)
        elif t > time + 2 * planet:
            improvements.append(0)
        else:
            improvements.append(planet - (0.5 * (t- time)))

    imp = sorted(improvements, reverse=True)
    print int(2*sum(planets) - sum(imp[:L]))




for tt in range(t):
    inp = map(int, sys.stdin.readline().split())
    print "Case #%d:" %(tt+1),
    space(*inp)
