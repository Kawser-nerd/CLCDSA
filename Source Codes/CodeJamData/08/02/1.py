import re

##f = open('B-test.in', 'r')
##f = open('B-small-attempt1.in', 'r')
f = open('B-large.in', 'r')


N_cases = int(re.search('\d+',f.readline()).group(0))

for case in range(N_cases):
    T = int(re.search('\d+',f.readline()).group(0))

    aux = re.findall('\d+', f.readline())
    NA = int(aux[0])
    NB = int(aux[1])

    atobd = []
    atoba = []
    for t in range(NA):
        aux = re.findall('\d{2}', f.readline())
        dh = int(aux[0])
        dm = int(aux[1])
        d = dh*60 + dm

        ah = int(aux[2])
        am = int(aux[3])
        a = ah*60 + am + T

        atobd.append((d,1))
        atoba.append((a,-1))

    btoad = []
    btoaa = []
    for t in range(NB):
        aux = re.findall('\d{2}', f.readline())
        dh = int(aux[0])
        dm = int(aux[1])
        d = dh*60 + dm

        ah = int(aux[2])
        am = int(aux[3])
        a = ah*60 + am + T

        btoad.append((d,1))
        btoaa.append((a,-1))

    at_A = btoaa + atobd
    at_A.sort()

    at_B = atoba + btoad
    at_B.sort()

    inv_A = []
    s = 0
    for k,v in at_A:
        s += v
        inv_A.append(s)

    inv_B = []
    s = 0
    for k,v in at_B:
        s += v
        inv_B.append(s)

    start_A = max(inv_A)
    if start_A < 0:
        start_A = 0

    start_B = max(inv_B)
    if start_B < 0:
        start_B = 0

    print 'Case #%(c)d: %(sa)d %(sb)d' % {'c':(case + 1), 'sa':start_A, 'sb':start_B}

f.close()