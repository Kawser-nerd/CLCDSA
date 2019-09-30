#!/usr/bin/python2.6
import os, sys, re, math
stdin = sys.stdin

text = ''
pos = 0

class Tree:
    def __init__(self, w):
        self.l = None
        self.r = None
        self.w = w
        self.s = None

    def eval(self, features):
        if self.s is None:
            return self.w
        else:
            if self.s in features:
                return self.w * self.l.eval(features)
            else:
                return self.w * self.r.eval(features)


def parse():
    global text, pos

    assert text[pos] == '('
    pos += 1

    s = ''
    while text[pos] == '.' or (ord('0') <= ord(text[pos]) <= ord('9')):  
        s += text[pos]
        pos += 1
    
    tree = Tree(float(s))

    s = ''
    while text[pos] != ')' and text[pos] != '(':
        s += text[pos]
        pos += 1

    if s == '':
        assert text[pos] == ')'
        pos += 1
        return tree
    else:
        tree.s = s
        tree.l = parse()
        tree.r = parse()
        assert text[pos] == ')'
        pos += 1
        return tree


def main():
    global text, pos

    T = int(stdin.readline())
    for cs in range(1,T+1):
        print 'Case #%d:' % cs
        L = int(stdin.readline())
        text = ''
        pos = 0
        for each in range(L):
            text += ' ' + stdin.readline().strip()
        text = ''.join(text.split())
        text += '$'

        tree = parse()

        M = int(stdin.readline())
        for each in range(M):
            v = stdin.readline().split()
            print '%.7f' %tree.eval(set(v[2:]))

main()
