import sys
stdin = sys.stdin


def solve():
    tmp = stdin.readline().strip().split(" ")
    R,C = int(tmp[0]), int(tmp[1])
    data = []
    for r in range(R):
        row = stdin.readline().strip()
        data.append(row)

    allowed = [[['^','v','<','>'] for c in range(C)] for r in range(R)]

    for r in range(R):
        # scan rows
        for c in range(C):
            if data[r][c] != '.':
                if '<' in allowed[r][c]:
                    allowed[r][c].remove('<')
                break
        # opposite order
        for c in range(C-1, -1, -1):
            if data[r][c] != '.':
                if '>' in allowed[r][c]:
                    allowed[r][c].remove('>')
                break
    for c in range(C):
        # scan cols
        for r in range(R):
            if data[r][c] != '.':
                if '^' in allowed[r][c]:
                    allowed[r][c].remove('^')
                break
        for r in range(R-1, -1, -1):
            if data[r][c] != '.':
                if 'v' in allowed[r][c]:
                    allowed[r][c].remove('v')
                break

    cnt = 0
    for r in range(R):
        for c in range(C):
            if data[r][c]=='.':
                continue
            if not allowed[r][c]:
                return None
            if data[r][c] not in allowed[r][c]:
                cnt+=1
    return cnt



if __name__ == "__main__":
    cases = int(stdin.readline().strip())
    for case in range(cases):
        result = solve()
        print "Case #%d: %s" % (case+1, str(result) if result is not None else "IMPOSSIBLE")
