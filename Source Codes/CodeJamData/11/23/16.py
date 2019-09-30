from pprint import pprint

# by: Jeremy Holman, jeremy.holman@gmail.com
# for: Google Code Jam 2011, Round 1B
# problem C: House of Kittens

def splithouse(rooms, U, V):
    # find j such that rooms[j] contains both U and V
    for i in range(len(rooms)):
        room = rooms[i]
        if U in room and V in room:
            # cut it into two rooms
            u = room.index(U)
            v = room.index(V)
            u,v = min(u,v,), max(u,v)
            room1 = map(lambda (x,y): y, filter(lambda (x,y): x>=u and x<=v, enumerate(room)))
            room2 = map(lambda (x,y): y, filter(lambda (x,y): x<=u or  x>=v, enumerate(room)))
            rooms.pop(i)
            return rooms + [room1,room2]

def test_coloring(rooms, coloring, numcolors):
    for room in rooms:
        roomcolors = set(map(lambda x: coloring[x-1], room))
        if len(roomcolors) < numcolors:
            return False
    return True

def find_coloring_help(rooms, partial, numcolors):
    # remember, if we can't satisfy numcolors, return None
    # print partial 
    try:
        todo = partial.index(None)
    except ValueError:
        if test_coloring(rooms, partial, numcolors):
            return partial
        else:
            return None
    for i in range(numcolors):
        partial[todo] = i+1
        attempt = find_coloring_help(rooms, partial, numcolors)
        if attempt:
            partial[todo] = i+1
            return attempt
        partial[todo] = None

def find_coloring(rooms, numpillars, numcolors):
    assert numcolors < numpillars
    partial = [None] * numpillars
    partial[0] = 1
    return find_coloring_help(rooms, partial, numcolors)


# Now we start reading input and doing stuff!

T = int(raw_input().strip())

for case in range(1,T+1):
    (N,M) = map(int,raw_input().strip().split(' '))
    U = map(int,raw_input().strip().split(' '))
    V = map(int,raw_input().strip().split(' '))
    walls = zip(U,V)

    # split up the house
    rooms = [ range(1,N+1) ]
    for wall in walls:
        rooms = splithouse(rooms, wall[0], wall[1])
    rooms.sort(key=len)

    for i in range(min(map(len,rooms)),0,-1):
        coloring = find_coloring(rooms, N, i)
        if coloring:
            break


    print "Case #%d: %s" % (case, i)
    print ' '.join(map(str,coloring))
