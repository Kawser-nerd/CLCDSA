from collections import deque


def filter_space_list(strs):
    space_list = []
    h = 1
    for str in strs:
        w = 1
        for char in str:
            if char == ".":
                space_list.append((h, w))
            w += 1
        h += 1
    return space_list


def create_graph(strs):
    space_list = filter_space_list(strs)
    graph = {}
    for space in space_list:
        graph[space] = [
            x for x in [
                (space[0]+1, space[1]),
                (space[0], space[1]+1),
                (space[0]-1, space[1]),
                (space[0], space[1]-1),
            ] if x in space_list
        ]
    return graph


def get_parent(searched, spaces):
    for space in spaces:
        if space in searched.keys():
            return space
    return None


def main(input_list):
    sy, sx = list(map(int, input_list[0][1].split()))
    gy, gx = list(map(int, input_list[0][2].split()))
    start = (sy, sx)
    goal = (gy, gx)

    graph = create_graph(input_list[1])

    search_queue = deque()
    search_queue += graph[start]
    searched = {}
    searched[start] = None

    while search_queue:
        space = search_queue.popleft()

        if not space in searched.keys():
            search_queue += graph[space]
            space_parent = get_parent(searched, graph[space])
            searched[space] = space_parent

        if space == goal:
            break

    some_parent = searched[goal]
    route_reversed = []
    route_reversed.append(goal)
    while not some_parent is None:
        route_reversed.append(some_parent)
        some_parent = searched[some_parent]

    return len(route_reversed) - 1


if __name__ == "__main__":
    input_list = []
    input_list.append([input(), input(), input()])
    input_strs = []
    for _ in range(int(input_list[0][0].split()[0])):
        input_strs.append(input())
    input_list.append(input_strs)
    print(main(input_list))