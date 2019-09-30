import psyco
psyco.full()

def solve(N, M, A):
    for x1 in range(N + 1):
        for y1 in range(M + 1):
            for x2 in range(N + 1):
                for y2 in range(M + 1):
                    S = abs(x1 * y2 - x2 * y1)
                    if S == A:
                        return "%d %d %d %d %d %d"  % (0, 0, x1, y1, x2, y2)
    return "IMPOSSIBLE"

if __name__ == '__main__':
    C = input()
    for case in range(C):
        N, M, A = map(int, raw_input().split(' '))
        print "Case #%d:" % (case + 1), solve(N, M, A)

        
