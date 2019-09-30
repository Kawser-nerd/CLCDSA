from math import sqrt

def d(x,y,z):
    return sqrt(x*x + y*y + z*z)
s = raw_input()
cases = int(s)
for case in range(cases):
    print 'Case #%d:' % (case+1),
    s = raw_input()
    nf = int(s)
    r = [0,0,0]
    v = [0,0,0]
    for f in range(nf):
        s = raw_input()
        n = s.split(' ')
        r[0] = r[0] + int(n[0])
        r[1] = r[1] + int(n[1])
        r[2] = r[2] + int(n[2])
        v[0] = v[0] + int(n[3])
        v[1] = v[1] + int(n[4])
        v[2] = v[2] + int(n[5])
    r[0] = r[0] / float(nf)
    r[1] = r[1] / float(nf)
    r[2] = r[2] / float(nf)
    v[0] = v[0] / float(nf)
    v[1] = v[1] / float(nf)
    v[2] = v[2] / float(nf)
    dot = v[0] * r[0] + v[1] * r[1] + v[2] * r[2]
    if dot >= 0:
        print '%0.8f %0.8f' % (d(r[0],r[1],r[2]),0)
    else:
        p = -dot / float(d(v[0],v[1],v[2])**2)
        v[0] = v[0] * p
        v[1] = v[1] * p
        v[2] = v[2] * p
	for i in range(3):
            r[i] = r[i] + v[i]
        print '%0.8f %0.8f' % (d(r[0],r[1],r[2]),p)