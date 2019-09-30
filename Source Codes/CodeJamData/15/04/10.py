def main():
    num_cases = input()
    for case in range(num_cases):
        x, rows, cols = map(int, raw_input().split())
        print 'Case #%d: %s' % (case + 1, 'GABRIEL' if gabriel_wins(x, rows, cols) else 'RICHARD')

def gabriel_wins(x, rows, cols):
    if x >= 7:
        # Richard can chose an X-omino which encloses a space.
        return False
    for omino in get_ominos(x):
        if not gabriel_wins_with_omino(x, rows, cols, omino):
            return False
    return True

def gabriel_wins_with_omino(x, rows, cols, omino):
    for transformed_omino in omino_transformations(omino):
        rs = omino_rs(transformed_omino)
        cs = omino_cs(transformed_omino)
        for r_offset in range(rows - rs + 1):
            for c_offset in range(cols - cs + 1):
                offset = (r_offset, c_offset)
                if gabriel_wins_with_omino_offset(x, rows, cols, transformed_omino, offset):
                    return True
    return False

def gabriel_wins_with_omino_offset(x, rows, cols, omino, offset):
    covered = set()
    for point in omino:
        covered.add((point[0] + offset[0], point[1] + offset[1]))
    for r_start in range(rows):
        for c_start in range(cols):
            if (r_start, c_start) in covered: continue

            group = get_contiguous_group(covered, rows, cols, (r_start, c_start))
            if len(group) % x != 0:
                # We'll have a remainder regardless of which ominos we pick.
                return False
            for p in group:
                covered.add(p)
    return True

def get_contiguous_group(covered, rows, cols, start):
    group = {start}
    active = {start}
    while active:
        point = r, c = next(iter(active))
        active.remove(point)

        for dr, dc in (-1, 0), (1, 0), (0, -1), (0, 1):
            new_point = new_r, new_c = r + dr, c + dc
            if new_r >= 0 and new_c >= 0 and new_r < rows and new_c < cols \
                    and new_point not in group and new_point not in covered:
                group.add(new_point)
                active.add(new_point)
    return group

def get_row(p):
    return p[0]

def get_col(p):
    return p[1]

# Return the number of rows an omino spans.
def omino_rs(omino):
    return max(map(get_row, omino)) + 1

# Return the number of columns an omino spans.
def omino_cs(omino):
    return max(map(get_col, omino)) + 1

def normalized(a):
    min_r = min(map(get_row, a))
    min_c = min(map(get_col, a))
    b = set()
    for p in a:
        b.add((p[0] - min_r, p[1] - min_c))
    return b

def get_ominos(x):
    if x == 1: return [{(0, 0)}]

    ominos = []
    for smaller_omino in get_ominos(x - 1):
        contig_points = set()
        for point in smaller_omino:
            for dr, dc in ((0, -1), (0, 1), (-1, 0), (1, 0)):
                new_point = (point[0] + dr, point[1] + dc)
                if new_point not in smaller_omino:
                    contig_points.add(new_point)
        for point in contig_points:
            omino = smaller_omino.copy()
            omino.add(point)
            omino = normalized(omino)
            if not contains_equiv(ominos, omino):
                ominos.append(omino)
    return ominos

def contains_equiv(ominos, omino):
    for other_omino in ominos:
        if equiv_ominos(other_omino, omino):
            return True
    return False

def omino_transformations(omino):
    for sign_r, sign_c in (+1, +1), (+1, -1), (-1, +1), (-1, -1):
        normal = lambda (r, c): (r * sign_r, c * sign_c)
        swapped = lambda (r, c): (c * sign_c, r * sign_r)
        for f in normal, swapped:
            yield normalized(map(f, omino))

def equiv_ominos(a, b):
    return a in omino_transformations(b)

def to_text(o):
    return '\n'.join([''.join(['#' if (r, c) in o else ' ' for c in range(omino_cs(o))]) for r in range(omino_rs(o))])

if __name__ == '__main__':
    main()
