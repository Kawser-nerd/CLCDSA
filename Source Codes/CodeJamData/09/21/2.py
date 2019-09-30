
def tokens(treelines):
    for line in treelines:
        for t in line.split():
            if t[0]=='(':
                yield '('
                t=t[1:]
            if not t:
                continue
            if t[-1]==')':
                tt=t[:-1]
                if tt:
                    yield tt
                yield ')'
            else:
                yield t
    return

class Node(object):
    def __init__(self, p, feature, left=None, right=None):
        self.p=p
        self.feature=feature
        self.left = left
        self.right = right
        return

    @classmethod
    def from_tokens(cls, tokens):
        b = tokens.next()
        assert b=='('
        p = float(tokens.next())
        n = tokens.next()
        if n==')':
            feature = None
            left=None
            right=None
        else:
            feature = n
            left=cls.from_tokens(tokens)
            right=cls.from_tokens(tokens)
            b=tokens.next()
            assert b==')'
        node = cls(p, feature, left, right)
        return node

    def find(self, features):
        if self.feature is None:
            return self.p
        if self.feature in features:
            pp = self.left.find(features)
        else:
            pp = self.right.find(features)
        return self.p*pp

def docase(f):
    n=int(f.readline())
    lines = [f.readline() for i in range(n)]
    tree = Node.from_tokens(tokens(lines))

    n=int(f.readline())
    for i in range(n):
        line = f.readline().split()
        features = set(line[2:])
        r = tree.find(features)
        print '%.7f'%r
    return



def main(fn):
    f=open(fn)
    n = int(f.readline())
    for i in range(n):
        print 'Case #%d:'%(i+1)
        docase(f)
    return

import sys
main(*sys.argv[1:])
