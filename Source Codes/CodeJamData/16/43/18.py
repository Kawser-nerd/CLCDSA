import sys


TOP, RIGHT, BOTTOM, LEFT = range(4)

Direction = {
    (TOP, '\\'): RIGHT,
    (TOP, '/'): LEFT,
    (RIGHT, '\\'): TOP,
    (RIGHT, '/'): BOTTOM,
    (BOTTOM, '\\'): LEFT,
    (BOTTOM, '/'): RIGHT,
    (LEFT, '\\'): BOTTOM,
    (LEFT, '/'): TOP,
}

Offsets = {
    TOP: (-1,0),
    RIGHT: (0, 1),
    BOTTOM: (1, 0),
    LEFT: (0, -1)
}

Opposite = {
    TOP:BOTTOM,
    BOTTOM:TOP,
    LEFT:RIGHT,
    RIGHT:LEFT
}

def follow(Maze, (i,j), entered, R, C):
    to = Direction[entered, Maze[i][j]]
    di, dj = Offsets[to]
    i += di
    j += dj

    if i == 0:
        return j
    elif j == C+1:
        return C + i
    elif i == R+1:
        return C + R + (C + 1 - j)
    elif j == 0:
        return C + R + C + (R + 1 - i)

    return follow(Maze, (i,j), Opposite[to], R, C)

def verify(Maze, R, C, Cs):
    top = range(1, C+1)

    #print Cs

    for courtier in top:
        i = 1
        j = courtier
        end = follow(Maze, (i,j), TOP, R, C)
        if (courtier, end) not in Cs and (end, courtier) not in Cs:
            #print courtier, 'invalidates to', end
            return False

    right = range(C+1, C+1+R)

    for courtier in right:
        j = C
        i = courtier - C
        end = follow(Maze, (i,j), RIGHT, R, C)
        if (courtier, end) not in Cs and (end, courtier) not in Cs:
            #print courtier, 'invalidates to', end
            return False

    bottom = range(C+1+R, 2*C + 1 + R)

    for courtier in bottom:
        i = R
        j = C - (courtier - R - C) + 1
        end = follow(Maze, (i,j), BOTTOM, R, C)
        if (courtier, end) not in Cs and (end, courtier) not in Cs:
            #print courtier, 'invalidates to', end
            return False

    left = range(2*C + 1 + R, 2*C + 2*R + 1)

    for courtier in left:
        i = R - (courtier - R - C - C) + 1
        j = 1
        end = follow(Maze, (i,j), LEFT, R, C)
        if (courtier, end) not in Cs and (end, courtier) not in Cs:
            #print courtier, 'invalidates to', end
            return False

    return True


def generate_mazes(R, C):
    stack = ['']
    while len(stack[0]) < R*C:
        next_stack = []
        for s in stack:
            next_stack.append(s + '/')
            next_stack.append(s + '\\')
        stack = next_stack
    for s in stack:
        ret = [['x' for j in xrange(C+2)] for i in xrange(R+2)]
        for i in xrange(R):
            for j in xrange(C):
                ret[i+1][j+1] = s[i*C + j]
        yield ret


def print_maze(maze, R, C):
    for i in xrange(1,R+1):
        print ''.join(maze[i][j] for j in xrange(1,C+1))
    print


def solve(R, C, Cs):
    pairs = set()
    for i in range(len(Cs)/2):
        pairs.add((Cs[2*i],Cs[2*i+1]))

    for maze in generate_mazes(R, C):
        #print_maze(maze, R, C)
        xx = verify(maze, R, C, pairs)
        #print xx
        if xx:
            return '\n'.join(''.join(maze[i][j] for j in xrange(1, C+1)) for i in xrange(1, R+1))


    return 'IMPOSSIBLE'

def main():
    T = int(sys.stdin.readline().strip())

    for i in xrange(T):
        R, C = map(int, sys.stdin.readline().strip().split())
        Cs = map(int, sys.stdin.readline().strip().split())
        assert len(Cs) == 2 * (R + C)
        ans = solve(R, C, Cs)
        print 'Case #%s:' % (i+1)
        print ans

if __name__ == '__main__':
    main()
