from sys import stdin
from sys import stdout

def find_opening_paren(content):
    depth = 0
    p = []
    for i, c in enumerate(content):
        if c == '(':
            if depth == 0:
                p.append(i)
            depth += 1
        elif c == ')':
            depth -= 1
    return p

def parse_tree(text):
    i = text.find('(')
    j = text.rfind(')')
    content = text[i + 1:j].strip()
    parts = content.split()
    prob = float(parts[0])
    if len(parts) == 1:
        return (False, prob)
    else:
        feat = parts[1]
        p = find_opening_paren(content)
        left_tree = parse_tree(content[p[0]:p[1]])
        right_tree = parse_tree(content[p[1]:])
        return (True, prob, feat, left_tree, right_tree)

def compute(tree, feats):
    if tree[0]:
        dummy, prob, feat, left_tree, right_tree = tree
        if feat in feats:
            return prob * compute(left_tree, feats)
        else:
            return prob * compute(right_tree, feats)
    else:
        dummy, prob = tree
        return prob


N = int(stdin.readline().strip())
for x in xrange(1, N + 1):
    L = int(stdin.readline().strip())
    text = ''
    for i in xrange(L):
        text += stdin.readline()
    tree = parse_tree(text)
    stdout.write('Case #%d:\n' % x)
    A = int(stdin.readline().strip())
    for i in xrange(A):
        parts = stdin.readline().split()
        feats = set(parts[2:])
        prob = compute(tree, feats)
        stdout.write('%0.7f\n' % prob)
