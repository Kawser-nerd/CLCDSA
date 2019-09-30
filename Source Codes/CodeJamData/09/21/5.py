import re

class Tree(object):
  def __init__(self, value, feature=None, left=None, right=None):
    self.value = float(value)
    self.feature = feature
    self.left = left
    self.right = right

  def __str__(self):
    tree = '('
    tree += str(self.value)
    if self.feature:
      tree += ''.join([self.feature, str(self.left), str(self.right)])
    tree += ')'
    return tree

  def eval(self, animal):
    p = self.value
    if self.feature in animal:
      p *= self.left.eval(animal)
    elif self.feature:
      p *= self.right.eval(animal)
    return p


def parse_tree(tree):
  match = re.match('\(([\d\.]+)([a-z]*)(.*)', tree)
  value = match.group(1)
  feature = match.group(2)
  remaining = match.group(3)
  if not feature:
    remaining = remaining[1:]
    return Tree(value), remaining
  t = Tree(value, feature)
  t.left, remaining = parse_tree(remaining)
  t.right, remaining = parse_tree(remaining)
  return t, remaining[1:]

def main():
  N = int(raw_input())
  for t in range(1, N+1):
    print 'Case #%d:' % t
    L = int(raw_input())
    tree = ''
    for i in range(L):
      tree += raw_input()
    tree = re.sub('\s+', '', tree)
    tree, _ = parse_tree(tree)
    A = int(raw_input())
    for i in range(A):
      animal = set(raw_input().split()[2:])
      print '%.7f' % tree.eval(animal)

if __name__ == '__main__':
  main()
