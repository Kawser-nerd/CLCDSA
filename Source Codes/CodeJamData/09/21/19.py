import sys

def next_line():
    return sys.stdin.readline()

def next_line_x():
    line = next_line().replace('(', ' ').replace(')', ' ')
    l = line.split()
    if not l:
        return next_line_x()
    return l

class Node(object):
    def __init__(self, prob, name):
        self.prob = float(prob)
        self.name = name

def process_node():
    l = next_line_x()
    if len(l) == 2:
        node = Node( *l )
        node.yes = process_node()
        node.no = process_node()
    else:
        node = Node(l[0], None)
    return node

def run():
    lines = int(next_line())

    root = process_node()
    animals = int(next_line_x()[0])
    for a in range(animals):
        out = next_line().split()
        name = out[0]
        features = out[2:]

        node = root
        prob = node.prob
        
        while node.name:
            if node.name in features:
                node = node.yes
            else:
                node = node.no
            prob *= node.prob
        print "%.7f" % prob

def main():
    n = int(next_line())

    for nr in range(1,n+1):
        print "Case #%d:" % nr
        run()

main()
