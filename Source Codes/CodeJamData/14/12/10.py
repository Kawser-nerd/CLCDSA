def search(tree, root, parent):
    children = tree[root].copy()
    #print(root, children)
    if parent != 0:
        del children[children.index(parent)]
    if len(children) <= 1:
        return 1
    firstlarge = 0
    secondlarge = 0
    for child in children:
        result = search(tree, child, root)
        if result > firstlarge:
            secondlarge = firstlarge
            firstlarge = result
        elif result > secondlarge:
            secondlarge = result
    return firstlarge + secondlarge + 1

fin = open('B-large.in', 'r')
fout = open('out.txt', 'w')
t = int(fin.readline())
for casecount in range(1, t + 1):
    n = int(fin.readline())
    tree = [[] for x in range(0, n + 1)]
    for i in range(0, n - 1):
        xi, yi = map(int, fin.readline().split())
        tree[xi].append(yi)
        tree[yi].append(xi)
    result = 0
    for i in range(1, n + 1):
        temp = search(tree, i, 0)
        if temp > result:
            result = temp
    fout.write('Case #%d: %d\n' % (casecount, n - result))
fin.close()
fout.close()
