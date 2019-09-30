import sys
N, L = map(int, input().split())
sys.setrecursionlimit(200000)

class Node:
    def __init__(self, depth=0):
        self.parent = None
        self.children = {}
        self.depth = depth
    def add(self, n):
        self.children[n] = Node(self.depth+1)
    def has(self, n):
        return n in self.children
t = Node()
for i in range(N):
    s = input()
    nt = t
    for c in s:
        if not nt.has(c):
            nt.add(c)
        nt = nt.children[c]

def solve(node):
    global N, L
    ans = 0
    f = lambda d: (L - d) & -(L - d)
    if node.has('0'):
        ans ^= solve(node.children['0'])
    else:
        ans ^= f(node.depth)
    if node.has('1'):
        ans ^= solve(node.children['1'])
    else:
        ans ^= f(node.depth)
    return ans

ans = solve(t)
if ans == 0:
    print('Bob')
else:
    print('Alice')