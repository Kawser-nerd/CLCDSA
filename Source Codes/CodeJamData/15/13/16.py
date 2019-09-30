### Google code jam 2015
### Round 1A
### Problem C: Logging (small)
import itertools;


def Customers(T, times):
    ret = 0;
    for barberTime in times:
        ret += (T-1)/barberTime + 1;
    return ret;


def convex_hull(points):
    # Convex hull code, taken from wikibooks example
    if len(points) <= 1:
        return points
 
    def cross(o, a, b):
        return (a[0] - o[0]) * (b[1] - o[1]) - (a[1] - o[1]) * (b[0] - o[0])
 
    # Build lower hull 
    lower = []
    for p in points:
        while len(lower) >= 2 and cross(lower[-2], lower[-1], p) < 0:
            lower.pop()
        lower.append(p)
 
    # Build upper hull
    upper = []
    for p in reversed(points):
        while len(upper) >= 2 and cross(upper[-2], upper[-1], p) < 0:
            upper.pop()
        upper.append(p)
 
    # Concatenation of the lower and upper hulls gives the convex hull.
    # Last point of each list is omitted because it is repeated at the beginning of the other list. 
    return lower[:-1] + upper[:-1]    


def cutDownTrees(myTree, allTrees):
    totTrees = len(allTrees);
    cutTrees = 1;
    while (cutTrees < totTrees):
        subsetSet = list(itertools.combinations(allTrees, totTrees-cutTrees ));
        for subset in subsetSet:
            if myTree in convex_hull(list(subset)):
                print cutTrees
                return;
        cutTrees += 1;
        



Cases = int(raw_input());
for i in range(Cases):
    print "Case #%d:" % (i+1)

    N = int(raw_input());
    trees = [];
    sortedTrees = [];
    for i in range(N):
        tree = map(int, raw_input().split());
        trees.append( tree );
        sortedTrees.append( tree );
    
    sortedTrees.sort();
    hull = convex_hull(sortedTrees);
    
    for i in range(N):
        if (trees[i] in hull):
            print 0;
        else:
            cutDownTrees(trees[i], sortedTrees);

