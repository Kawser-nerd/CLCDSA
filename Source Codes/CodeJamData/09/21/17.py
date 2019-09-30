#!/usr/bin/env python

import sys


def brak (str):
    s = 0
    ret = ""
    while (1): 
        token,str = str.split (None, 1)
        if (token == "("): s = s+1
        elif (token == ")"): s = s - 1
        ret += token + " "

        if (s == 0): break

    return ret, str
    
    


def prob (features, tree):
    # is this a leaf? 
    if (len(tree.split()) == 3): 
        return float(tree.split()[1])

    assert (len(tree.split()) > 3)
    bleft, weight, feature, rest = tree.split (None, 3)
    
    left, rest = brak (rest)
    right, rest = brak (rest)

    if feature in features:
        return prob (features, left) * float (weight)
    else:
        return prob (features, right) * float (weight)
    
    

def test():
    l = int(sys.stdin.readline())
    tree = reduce (lambda x,y: x+y, [sys.stdin.readline() for i in range(l)])
    tree = tree.replace ("(", " ( ").replace (")", " ) ");

    a = int(sys.stdin.readline())
    for i in range(a):
        features = sys.stdin.readline().split ()[2:]
        print "%.10f" % prob (features, tree)

def main():
    t = int(sys.stdin.readline())
    for i in range(1,t+1): 
        print "Case #" + str(i) + ":" 
        test()
main ()
