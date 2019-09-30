# -*- coding: utf-8 -*-

def do(decision_tree, animal, features):
    probability = 1.0
    while decision_tree[1] is not None:
        probability *= decision_tree[0]
        if decision_tree[1] in features:
            decision_tree = decision_tree[2]
        else:
            decision_tree = decision_tree[3]
    probability *= decision_tree[0]
    return probability

def parse(decision_tree):
    decision_tree = decision_tree.replace('(', ' ( ').replace(')', ' ) ').split()
    return parse_tree(decision_tree)

def parse_tree(decision_tree):
    assert decision_tree[0] == '('
    decision_tree.pop(0)
    weight = float(decision_tree.pop(0))
    if decision_tree[0] == ')':
        decision_tree.pop(0)
        return weight, None, None, None
    feature = decision_tree.pop(0)
    tree1 = parse_tree(decision_tree)
    tree2 = parse_tree(decision_tree)
    assert decision_tree[0] == ')'
    decision_tree.pop(0)
    return weight, feature, tree1, tree2

n = int(raw_input())
for _n in xrange(1, n + 1):
    print 'Case #%d:' % _n
    l = int(raw_input())
    decision_tree = ''
    for _l in xrange(1, l + 1):
        decision_tree += raw_input() + ' '
    decision_tree = parse(decision_tree)
    a = int(raw_input())
    for _a in xrange(1, a + 1):
        fields = raw_input().split()
        animal = fields[0]
        features = fields[2:]
        print '%.7f' % do(decision_tree, animal, features)
