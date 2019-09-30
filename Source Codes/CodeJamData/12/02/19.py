f = open('B-large.in', 'r')
g = open('resultBlarge.txt', 'w')
T = int(f.next().strip())

for i in xrange(1,1+T):
    s = map(int, f.next().strip().split())
    N = s[0]
    S = s[1]
    p = s[2]
    scores = s[3:]
    if p >= 2:
        solid_score = 3*p-2
        surprise_score = 3*p-4
    elif p == 1:
        solid_score = 1
        surprise_score = 1
    elif p == 0:
        solid_score = 0
        surprise_score = 0
    solid = sum(sc >= solid_score for sc in scores)
    surprise = sum(sc >= surprise_score for sc in scores) - solid
    res = solid + min(surprise, S)
    g.write('Case #' + str(i) + ': ' + str(res) + '\n')
g.close()