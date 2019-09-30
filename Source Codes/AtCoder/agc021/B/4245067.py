def graham_scan(vertices: list):
    from math import atan2
    from operator import itemgetter

    vertices.sort(key=itemgetter(1))
    base_x, base_y = vertices[0][:2]
    vertices = sorted(vertices[1:], key=lambda p: atan2(p[1]-base_y, p[0]-base_x)) + vertices[:1]
    convex = vertices[-1:] + vertices[:1]
    pop, append = convex.pop, convex.append
    last_x, last_y = convex[-1][:2]

    for point, (x, y, *_) in zip(vertices[1:], vertices[1:]):
        while ((x - last_x) * (convex[-2][1] - last_y) -
               (y - last_y) * (convex[-2][0] - last_x) < 0):
            pop()
            last_x, last_y = convex[-1][:2]
        append(point)
        last_x, last_y = point[:2]

    return convex[:-1]


if __name__ == "__main__":
    from math import acos, sqrt, pi
    N = int(input())
    a = [list(map(int, input().split()))+[i] for i in range(N)]
    result = [0]*N
    convex_hull = graham_scan(a) * 2

    for (x2, y2, _), (x1, y1, i), (x3, y3, _) in zip(convex_hull, convex_hull[1:], convex_hull[2:]):
        vec1_x, vec1_y = x2-x1, y2-y1
        vec2_x, vec2_y = x3-x1, y3-y1
        result[i] = pi - acos((vec1_x*vec2_x + vec1_y*vec2_y) / (sqrt(vec1_x**2+vec1_y**2)*sqrt(vec2_x**2+vec2_y**2)))

    total = sum(result)
    for rad in result:
        print(rad/total)