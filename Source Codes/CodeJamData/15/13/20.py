# code for convex hull from https://en.wikibooks.org/wiki/Algorithm_Implementation/Geometry/Convex_hull/Monotone_chain#Python

def convex_hull(points):
    """Computes the convex hull of a set of 2D points.
 
    Input: an iterable sequence of (x, y) pairs representing the points.
    Output: a list of vertices of the convex hull in counter-clockwise order,
      starting from the vertex with the lexicographically smallest coordinates.
    Implements Andrew's monotone chain algorithm. O(n log n) complexity.
    """
 
    # Sort the points lexicographically (tuples are compared lexicographically).
    # Remove duplicates to detect the case we have just one unique point.
    points = sorted(set(points))
 
    # Boring case: no points or a single point, possibly repeated multiple times.
    if len(points) <= 1:
        return points
 
    # 2D cross product of OA and OB vectors, i.e. z-component of their 3D cross product.
    # Returns a positive value, if OAB makes a counter-clockwise turn,
    # negative for clockwise turn, and zero if the points are collinear.
    def cross(o, a, b):
        return (a[0] - o[0]) * (b[1] - o[1]) - (a[1] - o[1]) * (b[0] - o[0])
 
    # Build lower hull 
    lower = []
    for p in points:
        while len(lower) >= 2 and cross(lower[-2], lower[-1], p) <= 0:
            lower.pop()
        lower.append(p)
 
    # Build upper hull
    upper = []
    for p in reversed(points):
        while len(upper) >= 2 and cross(upper[-2], upper[-1], p) <= 0:
            upper.pop()
        upper.append(p)
 
    # Concatenation of the lower and upper hulls gives the convex hull.
    # Last point of each list is omitted because it is repeated at the beginning of the other list. 
    return lower[:-1] + upper[:-1]

from itertools import combinations

def collinear(p0, p1, p2):
    x1, y1 = p1[0] - p0[0], p1[1] - p0[1]
    x2, y2 = p2[0] - p0[0], p2[1] - p0[1]
    return x1 * y2 - x2 * y1 < 1e-12

for t in xrange(input()):
    n = input()
    pts = []
    ans = [n for i in xrange(n)]
    for i in xrange(n):
        x, y = map(int, raw_input().split())
        pts.append((x, y))
    for i in xrange(n, 0, -1):
        if all([x != n for x in ans]):
               break
        for x in combinations(pts, i):
            hull = convex_hull(x)
            hull.append(hull[0])
            lh = len(hull) - 1
            for j in xrange(n):
                if pts[j] in hull:
                    ans[j] = min(ans[j], n - i)
                else:
                    for k in xrange(lh):
                        if collinear(hull[k], hull[k + 1], pts[j]):
                            ans[j] = min(ans[j], n - i)
                            break
    print "Case #" + str(t + 1) + ": "
    for x in ans:
        print x
