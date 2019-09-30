#!/usr/bin/python

from sys import stdin, stdout, stderr
from collections import defaultdict

def read_int(strLine):
    return map(int,
               strLine.split(' '))

def read_string(strLine):
    return strLine.split(' ')

def read_float(strLine):
    return map(float,
               strLine.split(' '))

def rsreadline():
    return stdin.readline().rstrip('\r\n')

def gettoken(tree):
    tree = tree.lstrip(' ')
    t = ''
    rem = ''
    if tree[0] == '(':
        t = '('
        rem = tree[1:]
    elif tree[0] == ')':
        t = ')'
        rem = tree[1:]
    elif tree[0].isdigit():
        s = tree.find(' ')
        end = min(filter(lambda x: x>0, [tree.find(' '), tree.find('('), tree.find(')')]))
        t = tree[0:end]
        rem = tree[end:]
    else:
        end = min(filter(lambda x: x>0, [tree.find(' '), tree.find('('), tree.find(')')]))
        t = tree[0:end]
        rem = tree[end:]
    return (t,rem.lstrip(' '))

def parse(tree):
    t, tree = gettoken(tree)
    if t != '(':
        raise AssertionError("not started with (")
    w, tree = gettoken(tree)
    w = float(w)
    f, tree = gettoken(tree)
    if f == ')':
        return (w,), tree
    left, tree = parse(tree)
    right, tree = parse(tree)
    e, tree = gettoken(tree)
    if e != ')':
        raise AssertionError("doesn't end with )")
    return ((w, f, left, right), tree)

def eva(tree, features):
    if len(tree) == 1:
        return tree[0]
    if tree[1] in features:
        return tree[0]*eva(tree[2], features)
    else:
        return tree[0]*eva(tree[3], features)

def main():
    cCase = int(rsreadline())
    for iCase in range(0, cCase):
        lines = int(rsreadline())
        sttree = ""
        for i in xrange(0, lines):
            sttree += rsreadline()
        tree = parse(sttree)[0]
        tasks = int(rsreadline())
        print 'Case #' + str(iCase+1) + ':'
        for i in xrange(0, tasks):
            features = read_string(rsreadline())[2:]
            print '%.8f' % (eva(tree, features))
        stdout.flush()

main()
