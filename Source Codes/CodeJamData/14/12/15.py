import itertools

def isBinaryTree(tree, deleted):
    isValid = True
    hasRoot = False
    for node in tree.keys():
        if node not in deleted:
            count = 0
            for node2 in tree[node]:
                if node2 not in deleted:
                    count += 1
            if count == 2:
                if not hasRoot:
                    hasRoot = True
                else:
                    isValid = False
                    break
            elif count == 1 or count == 3:
                continue
            else:
                isValid = False
                break
    if isValid and hasRoot:
        all = []
        queue = []
        visited = []
        for node in tree.keys():
            if node not in deleted:
                all.append(node)
        queue.append(all[0])
        while len(queue) > 0:
            node = queue.pop(0)
            visited.append(node)
            for node2 in tree[node]:
                if node2 not in visited and node2 not in queue and node2 not in deleted:
                    queue.append(node2)
            print(queue, visited, all)
        print()
        return sorted(visited) == sorted(all)
    else:
        return False

with open('B.in') as f:
    with open('B.out', 'w') as f2:
        lines = f.readlines()
        output = ""
        currentLine = 1
        caseNumber = 1
        while currentLine < len(lines):
            N = int(lines[currentLine])
            edges = lines[currentLine+1:currentLine+N]
            currentLine += N

            # special cases
            if N == 1:
                possible = 0
            elif N == 2:
                print(edges)
                possible = 1
            else:
                tree = {}
                for x in range(1, N+1):
                    tree[x] = []

                for edge in edges:
                    [nodeA, nodeB] = [int(n) for n in edge.split(" ")]
                    tree[nodeA].append(nodeB)
                    tree[nodeB].append(nodeA)
                print(tree)

                possible = -1
                p = list(range(1, N+1))
                for r in range(N):
                    for deleted in itertools.combinations(p, r):
                        if isBinaryTree(tree, deleted):
                            possible = r
                            break
                    if possible > -1:
                        break

            output += "Case #" + str(caseNumber) + ": " + str(possible) + "\n"
            caseNumber += 1

        print(output)
        f2.write(output)