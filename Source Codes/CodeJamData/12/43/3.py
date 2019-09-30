import sys
import math

def concat_str(args):
    s = " "
    for arg in args:
        s += str(arg)
    return s

def debug(*args):
    sys.stderr.write(concat_str(args) + "\n")

def printf(*args):
    debug(*args)
    print concat_str(args)

def int_input():
    return map(int, raw_input().split(' '))


#######################################################

def read_input():
    N = int(raw_input())
    father = int_input()
    for i in range(N-1):
        father[i] -= 1

    tree = [[] for i in range(N)]
    for i in range(N-1):
        tree[father[i]].append(i)

    return N, tree, father

def fillSize(i, tree, result):
    result[i] =  1 + sum([fillSize(j, tree, result) for j in tree[i]])
    return result[i]

def fillPropagate(self, height, max_slope, tree, result, size):
    children = tree[self]
    result[self] = height

    self_size = size[self]

    sum = 0
    for child in children:
        child_slope = (max_slope - 50100)*(self_size - sum)/self_size + 50100
        child_height = height + (self - child) * child_slope

        fillPropagate(child, child_height, child_slope, tree, result, size)
        sum += size[child]

def checkPossible(father, N):
    for i in range(N-1):
        for j in range(i + 1, min(father[i], N-1)):
            if father[j] > father[i]:
                return False
    return True

def solve(N, tree, father):
    if not checkPossible(father, N):
        return "Impossible"

    result = [0 for i in range(N)]
    size = [0 for i in range(N)]
    fillSize(N-1, tree, size)
    fillPropagate(N-1, 500*1000*1000, 100*1000, tree, result, size)

    return " ".join([str(i) for i in result])



#######################################################

sys.setrecursionlimit(5000)

for n_test_case in range(1, int(raw_input()) + 1):
    debug("Solving case ", n_test_case)

    printf("Case #", n_test_case, ": ", str(solve(*read_input())))

