import sys

T = int(sys.stdin.readline().strip())

for x in range(1, T + 1):
    tokens = sys.stdin.readline().split()
    index = 0

    C = int(tokens[index])
    index += 1
    combine = {}
    for i in range(index, index + C):
        base1 = tokens[i][0]
        base2 = tokens[i][1]
        non_base = tokens[i][2]
        if base1 not in combine:
            combine[base1] = {}
        combine[base1][base2] = non_base
        if base2 not in combine:
            combine[base2] = {}
        combine[base2][base1] = non_base
    index += C

    D = int(tokens[index])
    index += 1
    oppose = {}
    for i in range(index, index + D):
        base1 = tokens[i][0]
        base2 = tokens[i][1]
        if base1 not in oppose:
            oppose[base1] = set()
        oppose[base1].add(base2)
        if base2 not in oppose:
            oppose[base2] = set()
        oppose[base2].add(base1)
    index += D

    N = int(tokens[index])
    index += 1
    to_invoke = tokens[index]
    index += 1

    element_list = []
    for base in to_invoke:
        if element_list and (base in combine) and (element_list[-1] in combine[base]):
            base2 = element_list.pop()
            element_list.append(combine[base][base2])
        elif element_list and (base in oppose) and any(e in oppose[base] for e in element_list):
            element_list = []
        else:
            element_list.append(base)
    sys.stdout.write('Case #%d: [%s]\n' % (x, ', '.join(element_list)))
