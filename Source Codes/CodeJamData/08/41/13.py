#!/usr/bin/python

import os
import sys

class node(object):
  def __init__(self, gate, ch, v=None):
    self.gate = gate
    self.ch = ch
    self.val = v
    self.nc = [1000000, 1000000]


def create_tree(inf):
  (M, V) = [int(x) for x in inf.readline().split()]
  tree = [node(-1, -1)]
  for i in xrange((M - 1)//2):
    (G, C) = [int(x) for x in inf.readline().split()]
    tree.append(node(G, C == 1))
  for i in xrange((M + 1)//2):
    v = int(inf.readline().strip())
    tree.append(node(2, False, v))
  return (tree, V)


def eval_tree(tree, st):
  if tree[st].gate == 2:
    return tree[st].val
  else:
    lv = eval_tree(tree, 2*st)
    rv = eval_tree(tree, 2*st + 1)
    if tree[st].gate == 1:
      tree[st].v = lv & rv
    else:
      tree[st].v = lv | rv
    return tree[st].val

def min_ch(tree, st, v):
  if tree[st].nc[v] < 1000000:
    return tree[st].nc[v]
  if tree[st].gate == 2:
    if tree[st].val == v:
      tree[st].nc[v] = 0
      return 0
    return 1000000
  if tree[st].gate == 1:
    if v == 1:
      n1 = min_ch(tree, 2*st, 1)
      n2 = min_ch(tree, 2*st + 1, 1)
      if tree[st].ch:
        num = min(n1 + n2, min(n1, n2) + 1)
      else:
        num = n1 + n2
      tree[st].nc[v] = num
      return num
    n1 = min_ch(tree, 2*st, 0)
    n2 = min_ch(tree, 2*st + 1, 0)
    num = min(n1, n2)
    tree[st].nc[v] = num
    return num
  if v == 1:
    n1 = min_ch(tree, 2*st, 1)
    n2 = min_ch(tree, 2*st + 1, 1)
    tree[st].nc[v] = min(n1, n2)
    return min(n1, n2)
  n1 = min_ch(tree, 2*st, 0)
  n2 = min_ch(tree, 2*st + 1, 0)
  num = n1 + n2
  if tree[st].ch:
    num = min(num, min(n1, n2) + 1)
  tree[st].nc[v] = num
  return num

  

N = int(sys.stdin.readline().strip())
for nc in xrange(1, N + 1):
  (tree, V) = create_tree(sys.stdin)
  mc = min_ch(tree, 1, V)
  if mc < 1000000:
    print "Case #%d: %d" % (nc, mc)
  else:
    print "Case #%d: IMPOSSIBLE" % nc
