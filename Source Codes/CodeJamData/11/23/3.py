import sys

def case_iterator(path):
    with file(path) as f:
        lines = iter(f)
        n = int(lines.next())
        
        for i in range(1, 1 + n):
            yield i, read_case(lines)
    
def line_tostr(line):
    ret = []
    for c in line:
        if c == '.':
            ret.append(None)
        else:
            ret.append(int(c))
    return ret        
       
def read_case(lines):
    n, m = [int(i) for i in lines.next().strip().split()]
    edges = [[None] * 2 for _ in xrange(m)]
    values = [int(i) for i in lines.next().strip().split()]
    for i in xrange(m):
        edges[i][0] = values[i] - 1
    values = [int(i) for i in lines.next().strip().split()]
    for i in xrange(m):
        edges[i][1] = values[i] - 1
     
    return n, edges

def choose(colors, rooms):
    min_satisfy = None
    
    to_satisfy = [None] * len(rooms)
    for i, r in enumerate(rooms):
        num_to_satisfy = sum(1 for i in r if colors[i] is None)
        to_satisfy[i] = num_to_satisfy
        if num_to_satisfy == 0:
            continue
        if min_satisfy is None or num_to_satisfy < min_satisfy:
            min_satisfy = num_to_satisfy
            
    candid = [r for i, r in enumerate(rooms) if to_satisfy[i] == min_satisfy]
    def key(x):
        return len(x)
    s = sorted(candid, key=key)
    return s[0]

import random
def color_room(room, colors, num_colors, edges):
    room_colors = set(colors[i] for i in room if colors[i] is not None)
    uncolored_nodes = sorted([i for i in room if colors[i] is None])
    colors_to_use = sorted(set(xrange(num_colors)) - room_colors) 
    
    to_color = max(0, num_colors - len(room_colors))
    for _ in xrange(to_color):
        node = uncolored_nodes.pop(0)
        node_color = colors_to_use.pop(0)
        colors[node] = node_color
        
    while uncolored_nodes:
        node = uncolored_nodes.pop(0)
        node_edges = [e for e in edges if node in e]
        neigh = set()
        for e in node_edges:
            neigh.update(e)
        if neigh:
            neigh.remove(node)
            neigh_colors = set(colors[i] for i in neigh if colors[i] is not None)
            colors_to_use = set(xrange(num_colors)) - neigh_colors
            if colors_to_use:
                color = colors_to_use.pop()
            else:
                color = random.choice(xrange(num_colors))
        else:
            color = random.choice(xrange(num_colors))
        colors[node] = color

def solve(case):
    n, edges = case
    
    rooms = [set(range(n))]
    
    for e in edges:
        u, v = e
        found = None
        for r in rooms:
            if u in r and v in r:
                found = r
                
        assert found is not None
        rooms.remove(found)
        room_a = set([i for i in found if i >= u and i <= v])
        room_b = set([i for i in found if i >= v or i <= u])
        rooms.append(room_a)
        rooms.append(room_b)
        
    colors = [None] * n
    num_colors = min(len(r) for r in rooms) 
    
    while None in colors:
        room = choose(colors, rooms)
        color_room(room, colors, num_colors, edges)
        
    ret = str(num_colors) + '\n'
    ret += ' '.join(str(i + 1) for i in colors)
    return ret   
    
def main():
    try:
        path, = sys.argv[1:]
    except ValueError:
        sys.exit('usage: %s <input file>' % (sys.argv[0],))
    
    for i, case in case_iterator(path):
        print 'Case #%d: %s' % (i,solve(case))
        

if __name__ == '__main__':
    main()
