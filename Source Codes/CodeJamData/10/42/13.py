import sys

class Node:
    
    def __init__(self, m, cost, num):
        self.num = num
        self.m = m
        self.cost = cost
        self.left = None
        self.right = None
        self.parent = None
        
mem = None
        
def solve(node, x, ll):
    if node.cost < 0:
        return 0
    
    if node.m-x == 0:
        return 0
    else:
        if (node.num, x) in mem:
            return mem[(node.num, x)]
        
        A = node.cost + solve(node.left, x+1, ll-1) + solve(node.right, x+1, ll-1)
        if node.m-x <= ll-1:
            B = solve(node.left, x, ll-1) + solve(node.right, x, ll-1)
            
             
            ret = min(A, B)
        else:
            ret = A
        
        mem[(node.num, x)] = ret
        return ret
         
        
def tc(num):
    global mem
    mem = dict()
    
    p = int(sys.stdin.readline().strip())
    M = [int(m) for m in sys.stdin.readline().split()]
    C = []
    for i in range(p):
        C = C + [int(c) for c in sys.stdin.readline().split()]
    
    ctr = 0
    Q = []
    for i in range(2**p):
        ctr += 1
        Q.append(Node(p-M[i], -1, ctr))
    
    while len(Q) > 1:
        a = Q[0]
        b = Q[1]
        Q = Q[2:]
        ctr += 1
        n = Node(max(a.m, b.m), C[0], ctr)
        n.left = a
        n.right = b
        a.parent = n
        b.parent = n
        C = C[1:]
        Q.append(n)
        
    root = Q[0]
    
    print "Case #%d: %d" % (num, solve(root, 0, p))
    
T = int(sys.stdin.readline().strip())
for i in range(T):
    tc(i+1)
