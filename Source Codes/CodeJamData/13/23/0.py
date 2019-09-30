import sys
sys.setrecursionlimit(10000)

with open('garbled_email_dictionary.txt', 'r') as file:
    words = file.read().split()

def maketree(words):
    def addprefix(tree, w):
        for i in range(len(w)):
            c = w[i]
            if c not in tree:
                tree[c] = {}
            tree = tree[c]
        tree[''] = w

    tree = {}
    for w in words:
        addprefix(tree, w)
    return tree

from collections import namedtuple
State = namedtuple('State', ['left', 'tree', 'change', 'cost'])

prefix = maketree(words)

def _subsolve(message, tree, change):
    if not message:
        if '' in tree:
            return 0
        else:
            return None

    options = []
    if change > 0:
        # the letter must be identical
        c = message[0]
        if c in tree:
            options.append((message[1:], tree[c], change - 1, 0))
        if '' in tree and c in prefix:
            options.append((message[1:], prefix[c], change - 1, 0))
    else:
        # allow changes
        for c in tree:
            if c != '':
                if c == message[0]:
                    options.append((message[1:], tree[c], 0, 0))
                else:
                    options.append((message[1:], tree[c], 4, 1))

            else:
                # new word
                for d in prefix:
                    if d == message[0]:
                        options.append((message[1:], prefix[d], 0, 0))
                    else:
                        options.append((message[1:], prefix[d], 4, 1))

    best = None

    for (oleft, otree, ochange, cost) in options:
        if best is None or best > cost:
            tmp = subsolve(oleft, otree, ochange)
            if tmp is not None:
                best = tmp + cost if ((best is None) or (tmp + cost < best)) else best
    return best

subd = {}
def subsolve(message, tree, change):
    h = (message, id(tree), change)
    if h not in subd:
        subd[h] = _subsolve(message, tree, change)
    return subd[h]

def solve(message):
    return subsolve(message, prefix, 0)

    # frontier = [State(message, prefix, 0, 0)]
    # visited = set()

    # # count = 0
    # while frontier:
    #     # count += 1
    #     top = frontier[0]
    #     del frontier[0]

    #     if (top.left, id(top.tree), top.change, top.cost) in visited:
    #         # print (top.left, id(top.tree), top.change, top.cost)
    #         continue
    #     visited.add((top.left, id(top.tree), top.change, top.cost))

    #     # print (top.left, top.change, top.cost)

    #     if not top.left:
    #         if '' in top.tree:
    #             # print count
    #             return top.cost
    #         else:
    #             continue

    #     if top.change > 0:
    #         # the letter must be identical
    #         c = top.left[0]
    #         if c in top.tree:
    #             frontier.append(State(top.left[1:], top.tree[c], top.change - 1, top.cost))
    #         if '' in top.tree and c in prefix:
    #             frontier.append(State(top.left[1:], prefix[c], top.change - 1, top.cost))
    #     else:
    #         # allow changes
    #         for c in top.tree:
    #             if c != '':
    #                 if c == top.left[0]:
    #                     frontier.append(State(top.left[1:], top.tree[c], 0, top.cost))
    #                 else:
    #                     frontier.append(State(top.left[1:], top.tree[c], 4, top.cost + 1))
    #             else:
    #                 # new word
    #                 for d in prefix:
    #                     if d == top.left[0]:
    #                         frontier.append(State(top.left[1:], prefix[d], 0, top.cost))
    #                     else:
    #                         frontier.append(State(top.left[1:], prefix[d], 4, top.cost + 1))
    #     frontier.sort(key = lambda item: item.cost)

with open('C-large.in', 'r') as file:
    T = int(file.readline())
    for case in range(1, T+1):
        subd = {}
        message = file.readline().strip()
        print 'Case #{}: {}'.format(case, solve(message))
