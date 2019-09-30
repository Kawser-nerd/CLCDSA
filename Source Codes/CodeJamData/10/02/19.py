def gcd(a,b):
    """Return greatest common divisor using Euclid's Algorithm."""
    while b:      
 	 a, b = b, a % b
    return a

def gcdList (a):
    if len(a) == 1:
        return a[0]
    ret = gcd(a[0], a[1])
    for i in range(len(a)):
        ret = gcd(a[i], ret)
    return ret

f = open("B-large.in", 'r')
fc = f.readlines();
f.close()

for q in range(1, (int)(fc[0])+1):
    liczby = [(int)(l) for l in fc[q].split(' ')[1:]]
    ret = 0
    if len(liczby) > 1:
        roznice = []
        for i in range(len(liczby)):
            for j in range(i+1, len(liczby)):
                roznice.append (abs (liczby[i] - liczby[j]))
        g = gcdList (roznice)
        if liczby[0] % g > 0:
            ret = g - (liczby[0] % g)
    print ('Case #%d: %d' % (q, ret))
