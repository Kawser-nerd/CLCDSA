f = open('A-large2.in')
class DTree(object):
    def __init__(self, string):
        stripped = string.strip()[1:-1].strip()
        if ' ' in stripped:
            weight, rest = stripped.split(' ', 1)
            self.weight = float(weight)
#            print ">>>", rest, "<<<"
            feature, rest = rest.split('\n', 1)
            self.feature = feature
            rest = rest.strip()
            d = 1
            idx = 1
            while d > 0:
                if rest[idx] == '(':
                    d += 1
                elif rest[idx] == ')':
                    d -= 1
                idx += 1
            self.one = DTree(rest[:idx].strip())
            self.two = DTree(rest[idx:].strip())
        else:
            self.feature = None
            self.weight = float(stripped)
#        print self.weight

    def decide(self, features):
        p = self.weight
        if self.feature is not None:
            if self.feature in features:
                p *= self.one.decide(features)
            else:
                p *= self.two.decide(features)
        return p

N = int(f.readline().strip())
for n in range(N):
    print "Case #%s:" % (n+1,)
    L = int(f.readline().strip())
    l = ''
    for x in range(L):
        l += f.readline()
    tree = DTree(l)
    A = int(f.readline().strip())
    for a in range(A):
        features = f.readline().split()[2:]
        print "%.7f" % (tree.decide(features),)
