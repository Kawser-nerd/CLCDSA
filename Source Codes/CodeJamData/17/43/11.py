import sys
from collections import defaultdict

def get_beams(lines, ip, jp):
    beams = []
    for i in range(ip, -1, -1):
        if lines[i][jp] == '#' or lines[i][jp] == '-':
            break
        if lines[i][jp] == '|' or lines[i][jp] == '?':
            beams.append((i, jp, '|'))
            break

    for i in range(ip, len(lines)):
        if lines[i][jp] == '#' or lines[i][jp] == '-':
            break
        if lines[i][jp] == '|' or lines[i][jp] == '?':
            beams.append((i, jp, '|'))
            break

    for j in range(jp, -1, -1):
        if lines[ip][j] == '#' or lines[ip][j] == '|':
            break
        if lines[ip][j] == '-' or lines[ip][j] == '?':
            beams.append((ip, j, '-'))
            break

    for j in range(jp, len(lines[0])):
        if lines[ip][j] == '#' or lines[ip][j] == '|':
            break
        if lines[ip][j] == '-' or lines[ip][j] == '?':
            beams.append((ip, j, '-'))
            break
    return beams


def solve():
    r, c = map(int, raw_input().strip().split())
    lines = [raw_input().strip() for _ in range(r)]
    for i, line in enumerate(lines):
        lines[i] = ['?' if (x == '-' or x == '|') else x for x in line]

    for i in range(len(lines)):
        beam = False
        beam_i = 0
        beam_j = 0
        for j in range(len(lines[0])):
            if lines[i][j] == "#":
                beam = False
            elif lines[i][j] == ".":
                continue
            elif lines[i][j] == "?":
                if not beam:
                    beam = True
                    beam_i, beam_j = i, j
                else:
                    lines[beam_i][beam_j] = '|'
                    lines[i][j] = '|'

    for j in range(len(lines[0])):
        beam = False
        beam_i = 0
        beam_j = 0
        for i in range(len(lines)):
            if lines[i][j] == "#":
                beam = False
            elif lines[i][j] == ".":
                continue
            elif lines[i][j] == "?" or lines[i][j] == '|':
                if not beam:
                    beam = True
                    beam_i, beam_j = i, j
                else:
                    if lines[beam_i][beam_j] == '|' or lines[i][j] == '|':
                        print "IMPOSSIBLE"
                        return
                    lines[beam_i][beam_j] = '-'
                    lines[i][j] = '-'


    for _ in range(len(lines) * len(lines[0])):
        stop = True
        for ip in range(len(lines)):
            for jp in range(len(lines[0])):
                if lines[ip][jp] != '.':
                    continue
                beams = get_beams(lines, ip, jp)
                if len(beams) == 0:
                    print "IMPOSSIBLE"
                    return
                if len(beams) == 1:
                    lines[beams[0][0]][beams[0][1]] = beams[0][2]
                    stop = False
        if stop:
            break

    for i in range(len(lines)):
        for j in range(len(lines[0])):
            if lines[i][j] == '?':
                lines[i][j] = '-'

    print "POSSIBLE"
    for line in lines:
        print "".join(line)


if __name__ == '__main__':
    T = int(raw_input())
    for case_idx in xrange(1, T+1):
        sys.stdout.write("Case #{}: ".format(case_idx))
        solve()
