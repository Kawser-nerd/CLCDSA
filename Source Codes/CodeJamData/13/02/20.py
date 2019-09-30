import sys

def ok(arr):
    gg = [[0]*len(arr[0])]*len(arr)
    for i in range(len(arr)):
        if all(j for j in arr[i]):
            gg[i] = [1]*len(arr[i])
    for i in xrange(len(arr[0])):
        if all(arr[k][i] for k in range(len(arr))):
            for k in range(len(arr)):
                gg[k][i] = 1
    for i in range(len(arr)):
        for j in range(len(arr[i])):
            if arr[i][j] and not gg[i][j]:
                return False
    return True


def solve(arr):
    R = len(arr)
    C = len(arr[0])
    for t in range(100, 0, -1):
        qq = []
        for i in xrange(R):
            el = [1 if q <= t else 0 for q in arr[i]]
            qq.append(el)
        if not ok(qq):
            return "NO"
    return "YES"

def main():
    T = int(sys.stdin.readline())
    for cn in range(1, T+1):
        N, M = [int(x) for x in sys.stdin.readline().strip().split()]
        arr = [[int(x) for x in sys.stdin.readline().strip().split()]
                for y in xrange(N)]
        print "Case #%d: %s" % (cn, solve(arr))

if __name__ == '__main__':
    main()
        
