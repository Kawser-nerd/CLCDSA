from fractions import Fraction

T = int( input() )
for test in range(1,T+1):
    people = []
    G = int( input() )
    for g in range(G):
        di, hi, mi = [ int(x) for x in input().split() ]
        for h in range(hi):
            people.append( (di,mi+h) )

    assert len(people) <= 2

    d0, m0 = people[0]
    d1, m1 = people[1]

    t0 = Fraction( (360-d0) * m0, 360 )
    t1 = Fraction( (360-d1) * m1, 360 )

    t = max(t0,t1)

    prejde0 = t*360/m0
    prejde1 = t*360/m1

    if (prejde0 >= 720-d0) or (prejde1 >= 720-d1):
        print('Case #{}: {}'.format(test,1))
    else:
        print('Case #{}: {}'.format(test,0))


