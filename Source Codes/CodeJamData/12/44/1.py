import collections
import math
import sys

if __name__ == "__main__":
    f = sys.stdin
    if len(sys.argv) >= 2:
        fn = sys.argv[1]
        if fn != '-':
            f = open(fn)

    t = int(f.readline())
    for _t in xrange(t):
        R, C = map(int, f.readline().split())

        themap = []
        caves = {}
        for _r in xrange(R):
            line = f.readline().strip()
            assert len(line) == C
            for digit in xrange(10):
                if chr(ord('0') + digit) in line:
                    caves[digit] = (_r, line.find(chr(ord('0') + digit)))
            themap.append(line)

        assert sorted(caves.keys()) == range(len(caves))

        print "Case #%d:" % (_t + 1)
        for cave in xrange(len(caves)):
            reachable = set([caves[cave]])
            q = collections.deque([caves[cave]])

            while q:
                r, c = q.pop()
                def trymove(_r, _c):
                    if (_r, _c) not in reachable and themap[_r][_c] != '#':
                        reachable.add((_r, _c))
                        q.append((_r, _c))
                trymove(r-1, c)
                trymove(r, c-1)
                trymove(r, c+1)


            visited = set([tuple(sorted(reachable))])
            q = collections.deque([reachable])
            lucky = False
            while q:
                cur_plan = q.pop()
                # print cur_plan
                if len(cur_plan) == 1:
                    assert cur_plan.__iter__().next() in reachable
                    lucky = True
                    break

                for move in "left", "right", "down":
                    new_plan = set()
                    works = True
                    for r, c in cur_plan:
                        if move == "left":
                            new_p = (r, c-1)
                        if move == "right":
                            new_p = (r, c+1)
                        if move == "down":
                            new_p = (r+1, c)

                        if new_p in reachable:
                            new_plan.add(new_p)
                        elif themap[new_p[0]][new_p[1]] == '#':
                            new_plan.add((r, c))
                        else:
                            works = False
                            break

                    p = tuple(sorted(new_plan))
                    if works and p not in visited:
                        visited.add(p)
                        q.append(p)
                        # print move, "is good"
                    else:
                        pass
                        # print move, "is no good", works, tuple(sorted(new_plan)) in visited

            print "%d: %d %s" % (cave, len(reachable), "Lucky" if lucky else "Unlucky")


