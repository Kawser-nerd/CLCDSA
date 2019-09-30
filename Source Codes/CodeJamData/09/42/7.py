from heapq import *

def dijkstra(source, visit, weight=None, target=None, infinity=float('inf')):
    if weight is None:
        def weight(vertex, neighbor):
            return 1
    if target is None:
        def target(vertex):
            return False
    distances = {source: 0}
    parents = {source: []}
    queue = [(0, source)]
    visited = set()
    while queue:
        source_dist, source = heappop(queue)
        if target is not None and target(source):
            break
        visited.add(source)
        for neighbor in visit(source):
            if neighbor not in visited:
                new_neighbor_dist = source_dist + weight(source, neighbor)
                old_neighbor_dist = distances.setdefault(neighbor, infinity)
                if new_neighbor_dist < old_neighbor_dist:
                    distances[neighbor] = new_neighbor_dist
                    parents[neighbor] = [source]
                    heappush(queue, (new_neighbor_dist, neighbor))
        while queue and queue[0][1] in visited:
            heappop(queue)
    return source, distances, parents

def first_path(target, parents):
    path = []
    while parents[target]:
        path.append(target)
        target = parents[target][0]
    path.reverse()
    return path

def last_path(target, parents):
    path = []
    while parents[target]:
        path.append(target)
        target = parents[target][-1]
    path.reverse()
    return path

def solve(R, C, F, maze):
    def is_airhole(r, c, digs):
        return maze[r][c] == '.' or (r, c) in digs

    def visit(state):
        r, c, f, digs = state
        if f > F:
            return
        if r == R - 1:
            return
        if f:
            if is_airhole(r + 1, c, digs):
                yield r + 1, c, f + 1, digs
            else:
                yield r, c, 0, digs
        else:
            for dc in (-1, 1):
                if 0 <= c + dc <= C - 1:
                    if is_airhole(r, c + dc, digs):
                        if is_airhole(r + 1, c + dc, digs):
                            new_digs = frozenset((dr, dc) for dr, dc in digs if dr >= r + 1)
                            yield r + 1, c + dc, 1, new_digs
                        else:
                            yield r, c + dc, 0, digs
                            yield r, c, 0, digs.union([(r + 1, c + dc)])

    def get_weight(state_1, state_2):
        r1, c1, f1, digs_1 = state_1
        r2, c2, f2, digs_2 = state_2
        return max(0, len(digs_2) - len(digs_1))

    def is_target(state):
        r, c, f, digs = state
        return f <= F and r == R - 1

    target, distances, parents = dijkstra((0, 0, 0, frozenset()), visit, get_weight,
                                          is_target)
    return is_target(target), distances[target]

def main():
    N = int(raw_input())
    for case in xrange(1, N + 1):
        R, C, F = map(int, raw_input().split())
        maze = [raw_input() for _ in xrange(R)]
        success, cost = solve(R, C, F, maze)
        if success:
            result = 'Yes %d' % cost
        else:
            result = 'No'
        print 'Case #%d: %s' % (case, result)

if __name__ == '__main__':
    main()
