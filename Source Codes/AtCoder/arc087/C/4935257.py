import sys
input=sys.stdin.readline
sys.setrecursionlimit(10**9)
from collections import deque

class Node:
    def __init__(self,depth):
        self.depth=depth
        self.left=None
        self.right=None

def insert(node,s):
    n=node
    for i in range(len(s)):
        t=s[i]
        if t=='0':
            if n.left is None:
                n.left=Node(i+1)
            n=n.left
        else:
            if n.right is None:
                n.right=Node(i+1)
            n=n.right

class Trie:
    def __init__(self):
        self.root=Node(0)
    def insert(self,s:str):
        insert(self.root,s)

n,l=map(int,input().split())
S=[input().strip() for _ in range(n)]
trie=Trie()
for s in S:
    trie.insert(s)
Data=[]
q=deque([trie.root])

def dfs(node):
    if node.right is None and node.left is None:
        return
    if node.right is None or node.left is None:
        Data.append(l-node.depth)
    if node.right:
        q.append(node.right)
    if node.left:
        q.append(node.left)

while q:
    dfs(q.popleft())
xor=0

def Grundy(n):
    ret=1
    while n%2==0:
        n//=2
        ret*=2
    return ret

for i in Data:
    xor^=Grundy(i)
print('Alice' if xor else 'Bob')