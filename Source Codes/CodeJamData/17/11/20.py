import sys

def solve():
    print ""
    r, k = map(int, raw_input().strip().split())
    lines = []
    for _ in xrange(r):
        line = list(raw_input().strip())
        lines.append(line)

    for idx, line in enumerate(lines):
        if set(line) != set(['?']):
            if idx > 0:
                lines[0], lines[idx] = lines[idx], lines[0]
            break

    for idx, line in enumerate(lines):
        if set(line) == set(['?']):
            lines[idx] = lines[idx - 1]
            print ''.join(lines[idx])
        else:
            chars = filter(lambda x: x != '?', line)
            cur_char_idx = 0
            for i, el in enumerate(line):
                if el != '?' and el != chars[cur_char_idx]:
                    cur_char_idx += 1
                lines[idx][i] = chars[cur_char_idx]
            print ''.join(lines[idx])


if __name__ == '__main__':
    T = int(raw_input())
    for case_idx in xrange(1, T+1):
        sys.stdout.write("Case #{}: ".format(case_idx))
        solve()
