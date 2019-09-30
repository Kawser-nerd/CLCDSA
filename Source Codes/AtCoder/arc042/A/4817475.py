class Node(object):
    def __init__(self, value, prev, next):
        self.value = value
        self.prev = prev
        self.next = next

class Threads(object):
    def __init__(self, count):
        self.nodes = []
        for i in range(count + 2):
            self.nodes.append(Node(i, None, None))
        
        for i in range(count + 1):
            self.nodes[i].next = self.nodes[i+1]
            self.nodes[i+1].prev = self.nodes[i]
    
    def move_first(self, i):
        self.nodes[i].prev.next = self.nodes[i].next
        self.nodes[i].next.prev = self.nodes[i].prev
        self.nodes[i].prev = self.nodes[0]
        self.nodes[i].next = self.nodes[0].next
        self.nodes[i].prev.next = self.nodes[i]
        self.nodes[i].next.prev = self.nodes[i]

def main():
    n, m = map(int, input().split())
    threads = Threads(n)
    for _ in range(m):
        a = int(input())
        threads.move_first(a)
    
    node = threads.nodes[0].next
    while node != threads.nodes[-1]:
        print(node.value)
        node = node.next

main()