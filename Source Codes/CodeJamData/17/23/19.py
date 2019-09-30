def make_better_distances(distances):
    n = len(distances)
    converged = False
    while not converged:
        converged = True
        for x in range(n):
            for y in range(n):
                for z in range(n):
                    if x != y and x != z and y != z:
                        before = distances[x][z]
                        if distances[x][y] != -1 and distances[y][z] != -1:
                            distances[x][z] = min(distances[x][z], distances[x][y] + distances[y][z])
                        if distances[x][z] == -1:
                            distances[x][z] = float("inf")
                        after = distances[x][z]
                        if before != after:
                            converged = False
    return distances


def solve(horses, distances, pair):
    distances = make_better_distances(distances)
    n = len(horses)
    min_connections = []
    for i in range(n):
        min_connections.append([])
        for j in range(n):
            min_connections[-1].append(float("inf"))

    converged = False

    while not converged:
        converged = True
        # print("before iter")
        # for connection in min_connections:
        #     print(connection)
        # print('')
        for y in range(n):
            horse = horses[y]
            # mid_city = y
            # you're going through origin_city
            for z in range(n):
                if z != y:
                    # print("considering path from %s to %s" % (y, z))
                    # destination_city = z
                    distance = distances[y][z]
                    if distance != -1:
                        # print('cities %s and %s are conncted with distance %s vs horse %s' % (y, z, distance, horse[0]))
                        if distance <= horse[0]:
                            before = min_connections[y][z]
                            min_connections[y][z] = min(min_connections[y][z], float(distance)/horse[1])
                            after = min_connections[y][z]
                            if before != after:
                                converged = False

                    for x in range(n):
                        if x != y and x != z:
                            before = min_connections[x][z]
                            min_connections[x][z] = min(min_connections[x][z], min_connections[x][y] + min_connections[y][z])
                            after = min_connections[x][z]
                            if before != after:
                                converged = False
        # print("after iter")
        # for connection in min_connections:
        #     print(connection)
        # print('')

    return min_connections[pair[0]-1][pair[1]-1]



if __name__ == '__main__':

    # raw_input() reads a string with a line of input, stripping the '\n' (newline) at the end.
    # This is all you need for most Google Code Jam problems.
    t = int(raw_input())  # read a line with a single integer
    for i in xrange(1, t + 1):
        cake = []
        n, q = [int(s) for s in raw_input().split(" ")]  # read a list of integers, 2 in this case
        horses = []
        for j in range(n):
            e, s = [int(thing) for thing in raw_input().split(" ")]
            horses.append((e, s))
        connections = []
        for j in range(n):
            connections.append([int(thing) for thing in raw_input().split(" ")])

        city_pairs = []
        for j in range(q):
            u, v = [int(thing) for thing in raw_input().split(" ")]
            city_pairs.append((u, v))

        res = []
        for pair in city_pairs:
            res.append(solve(horses, connections, pair))

        print "Case #{}: {}".format(i, ' '.join([str(item) for item in res]))
        # check out .format's specification for more formatting options