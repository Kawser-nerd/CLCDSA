#!/usr/bin/env python



class Node:
    def __init__(self):
        self.exists = False
        self.children = {}

    def claim(self, subtree, exist_check = True):
        if exist_check:
            self.exists = True

        if len(subtree) == 0: return
        head = subtree[0]

        if not self.children.has_key(head):
            newNode = Node()
            self.children[head] = newNode

        childNode = self.children[head]
        childNode.claim(subtree[1:], exist_check)

    def count(self):
        result = 0
        if not self.exists: result += 1

        for key in self.children.iterkeys():
            childNode = self.children[key]
            result += childNode.count()

        return result

t = raw_input()

for i in xrange(1, int(t)+1):
    n, m = [int(x) for x in raw_input().strip().split()]
    root = Node()
    root.exists = True

    for j in xrange(0, n):
        exist_tree = raw_input().strip().split('/')
        root.claim(exist_tree[1:], True)
        
    for j in xrange(0, m):
        exist_tree = raw_input().strip().split('/')
        root.claim(exist_tree[1:], False)

    print "Case #%d: %d" % (i, root.count())
        

            
