from collections import defaultdict
import math
import sys

def numones(n):
    return bin(n).count('1')

def addchest(keys, chest):
    keys[chest[0]] -= 1
    for k in chest[1]:
        keys[k] += 1

def canchest(keys, chest):
    keys = dict(keys)
    for k in chest[1]:
        keys[k] -= 1
    return not any(v < 0 for v in keys.values())

if __name__ == "__main__":
    f = sys.stdin
    if len(sys.argv) >= 2:
        fn = sys.argv[1]
        if fn != '-':
            f = open(fn)

    t = int(f.readline())

    confs = range(2**20)
    confs.sort(key=numones, reverse=True)
    # print confs
    for _t in xrange(t):
        k, n = map(int, f.readline().split())
        _keys = map(int, f.readline().split())
        assert len(_keys) == k
        starting_keys = defaultdict(int)
        for k in _keys:
            starting_keys[k] += 1
        # print starting_keys

        chests = []
        for i in xrange(n):
            _data = map(int, f.readline().split())
            assert len(_data) == _data[1] + 2
            chests.append((_data[0], _data[2:]))
        # print chests

        # possible = { (2**n - 1) : None }
        possible = {}
        ending_keys = defaultdict(int, starting_keys)
        for c in chests:
            addchest(ending_keys, c)
        # print ending_keys
        if not any(v < 0 for v in ending_keys.values()):
            possible[2**n - 1] = None

        for c in confs:
            if c not in possible:
                continue

            keys = defaultdict(int, starting_keys)
            for i in xrange(n):
                if c & (1 << i):
                    addchest(keys, chests[i])
            # print bin(c), keys
            # assert not any(v < 0 for v in keys.values())

            for i in xrange(n):
                if not (c & (1 << i)):
                    continue
                if not canchest(keys, chests[i]):
                    continue

                c2 = c & (~(1<<i))
                if c2 not in possible or i < possible[c2]:
                    possible[c2] = i

        if 0 not in possible:
            print "Case #%d: IMPOSSIBLE" % (_t+1,)
        else:
            print "Case #%d:" % (_t+1,),
            cur = 0
            while True:
                n = possible[cur]
                if n is None:
                    break
                print n + 1,
                cur |= (1<<n)
            print
