import re

def parse(string):
    # Strip the parens.
    string = string.strip().strip('()').strip()
    weight = re.match(r'(\d+(?:\.\d+)?)', string).group(1)
    weight = float(weight)
    string = re.sub(r'(\d+(?:\.\d+)?)', '', string, 1).strip()
    if not string:
        return (None, weight,)
    # parse the feature
    feature = re.match(r'([a-z]+)', string).group(1)
    string = re.sub(r'([a-z]+)', '', string, 1).strip()
    # parse left and right.
    index, balance = 0, 0
    while balance > 0 or index == 0:
        if string[index] == '(':
            balance += 1
        elif string[index] == ')':
            balance -= 1
        index += 1
    ltree = string[0:index]
    rtree = string[index:]
    return (feature, weight, parse(ltree.strip()), parse(rtree.strip()))

def parse_animal(string):
    parts = string.split()
    count = int(parts[1])
    partset = frozenset(parts[2:])
    return partset

def evalscore(tree, animal):
    score = tree[1]
    if tree[0] is None:
        return score
    if tree[0] in animal:
        subtree = tree[2]
    else:
        subtree = tree[3]
    return score * evalscore(subtree, animal)

with open('A-large.in') as f:
    output = open('out.txt', 'w')
    cases = int(f.next())
    for i in range(1, cases + 1):
        output.write('Case #%d:\n' % (i,))
        treelines = int(f.next())
        treestr = ' '.join([f.next() for _ in range(treelines)])
        tree = parse(treestr)
        #print tree
        animalcount = int(f.next())
        animals = [parse_animal(f.next()) for _ in range(animalcount)]
        for ani in animals:
            #print ani
            score = evalscore(tree, ani)
            output.write('%.7f\n' % (score,))
    output.close()
# ok
