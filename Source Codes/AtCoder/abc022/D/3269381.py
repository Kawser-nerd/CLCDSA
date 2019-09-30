import sys


def graham_scan(vertices: list):
    from math import atan2
    from operator import itemgetter

    vertices.sort(key=itemgetter(1))
    base_x, base_y = vertices[0]
    vertices = sorted(vertices[1:], key=lambda p: atan2(p[1]-base_y, p[0]-base_x)) + vertices[:1]
    convex = vertices[-1:] + vertices[:1]
    pop, append = convex.pop, convex.append
    last_x, last_y = convex[-1]

    for point, (x, y) in zip(vertices[1:], vertices[1:]):
        while ((x - last_x) * (convex[-2][1] - last_y) -
               (y - last_y) * (convex[-2][0] - last_x) < 0):
            pop()
            last_x, last_y = convex[-1]
        append(point)
        last_x, last_y = point

    return convex[:-1]


def rotating_calipers(vertices: list):
    from math import hypot

    v_count = len(vertices)
    i, j = max_i, max_j = 0, v_count//2
    i_end, j_end = j, v_count
    (i_x, i_y), (i_next_x, i_next_y) = vertices[i], vertices[i+1]
    (j_x, j_y), (j_next_x, j_next_y) = vertices[j], vertices[j+1]
    dist = hypot(j_y - i_y, j_x - i_x)

    while i < i_end or j < j_end:
        if (i_next_x - i_x)*(j_next_y - j_y) - (i_next_y - i_y)*(j_next_x - j_x) < 0:
            i += 1
            i_x, i_y, (i_next_x, i_next_y) = i_next_x, i_next_y, vertices[(i+1) % v_count]
        else:
            j += 1
            j_x, j_y, (j_next_x, j_next_y) = j_next_x, j_next_y, vertices[(j+1) % v_count]
        _dist = hypot(j_y - i_y, j_x - i_x)
        if dist < _dist:
            dist = _dist
            max_i, max_j = i, j

    return max_i, max_j, dist


N = int(input())
A = [tuple(map(int, sys.stdin.readline().split())) for _ in [0]*N]
B = [tuple(map(int, l.split())) for l in sys.stdin]
convex_a = graham_scan(A)
convex_b = graham_scan(B)

print(rotating_calipers(convex_b)[2] / rotating_calipers(convex_a)[2])