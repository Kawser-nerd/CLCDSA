
import sys, collections
def read(): sys.stdout.flush(); return sys.stdin.readline().strip()

def max_size_of_full_tree(tree, root, seen):
    seen = seen | set([root])
    
    subtree_sizes = []
    for neighbor in tree[root]:
        if neighbor in seen:  continue
        subsize = max_size_of_full_tree(tree, neighbor, seen)
        subtree_sizes.append(subsize)
        
    if len(subtree_sizes) < 2:
        return 1

    subtree_sizes.sort(reverse = True)
    return 1 + subtree_sizes[0] + subtree_sizes[1]

tests = int(read())
for test in xrange(tests):
    N = int(read())
    tree = collections.defaultdict(list)
    for i in xrange(N - 1):
        a, b = read().split(" ")
        a, b = int(a), int(b)
        tree[a] += [b]
        tree[b] += [a]

    biggest_full_tree_size = 1
    for node in tree:
        size = max_size_of_full_tree(tree, node, set())
        if size > biggest_full_tree_size:
            biggest_full_tree_size = size
            
    answer = N - biggest_full_tree_size
    print "Case #%d: %d" % (test+1, answer)
