# -*- coding: utf-8 -*-

from pprint import pprint

VERBOSE = True
VERBOSE = False

class Pattern(object):

    def __init__(self, pattern_text):
        idx = 0
        lpat = len(pattern_text)
        items = []
        while idx < lpat:
            if pattern_text[idx] != '(':
                items.append(pattern_text[idx])
                idx = idx + 1
            else:
                rpos = pattern_text.find(')', idx+1)
                items.append(pattern_text[idx+1:rpos])
                idx = rpos + 1
        self.items = items

class Solver(object):

    def __init__(self, l, known_words):

        def add_to_tree(tree, word):
            if len(word) == 0: return
            c = word[0]
            if not (c in tree):
                tree[c] = dict()
            add_to_tree(tree[c], word[1:])

        self.word_tree = dict()
        for word in known_words:
            add_to_tree(self.word_tree, word)

        if VERBOSE:
            pprint (self.word_tree)

    def how_many(self, pattern_text):
        if VERBOSE: print "Testing pattern", pattern_text
        pattern = Pattern(pattern_text)
        trees = [ self.word_tree ]
        for patelem in pattern.items:
            if VERBOSE: print "... elem", patelem,
            new_trees = []
            for letter in patelem:
                for tree in trees:
                    if letter in tree:
                        new_trees.append(tree[letter])
            trees = new_trees
            if VERBOSE:
                print " ==> " 
                pprint(trees)
            if not trees:
                break
        return len(trees)

if __name__ == "__main__":
    import sys
    if not len(sys.argv) == 2:
        raise Exception("Give input as parameter")

    input = open(sys.argv[1])
    l, d, n = [ int(x) for x in input.readline().split() ]

    solver = Solver(l,
                    ( input.readline().strip()
                      for no in xrange(0, d)
                      ))

    for which, case in enumerate(input.readline().strip() for no in xrange(0, n)):
        print "Case #%d: %d" % (which + 1, solver.how_many(case))
