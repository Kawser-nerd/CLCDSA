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


def exists_space_from_searched_list(searched_list, space):
    for item in searched_list:
        if item[0] == space:
            return True
    return False


def get_space_from_searced_list_by_list(searched_list, space_list):
    for space in space_list:
        for searched in searched_list:
            if searched[0] == space:
                return searched
    return (None, 0)


def main(input_list):
    s_list = list(map(int, input_list[0][1].split()))
    sy = s_list[0]
    sx = s_list[1]
    start = (sy, sx)
    g_list = list(map(int, input_list[0][2].split()))
    gy = g_list[0]
    gx = g_list[1]
    goal = (gy, gx)
    graph = create_graph(input_list[1])

    search_queue = deque()
    search_queue += graph[start]
    searched_list = []

    while search_queue:
        space = search_queue.popleft()

        if not exists_space_from_searched_list(searched_list, space):
            search_queue += graph[space]
            space_old = get_space_from_searced_list_by_list(
                searched_list, graph[space])
            searched_list.append((space, space_old[1]+1))

        if space == goal:
            break

    return searched_list[-1][1]


if __name__ == "__main__":
    input_list = []
    input_list.append([input(), input(), input()])
    input_strs = []
    for _ in range(int(input_list[0][0].split()[0])):
        input_strs.append(input())
    input_list.append(input_strs)
    print(main(input_list))