from collections import defaultdict

def run_test(test_iteration):
    N, M = map(int, input().split())
    start_grid = [['.' for x in range(N)] for y in range(N)]
    free_rows = set(range(N))
    free_cols = set(range(N))
    # use sum = r + c, diff = r - c coords for diagonals
    free_sum = set(range(2 * N - 1))
    free_diff = set(range(- N + 1, N))
    for i in range(M):
        m, r, c = input().split()
        r, c = int(r) - 1, int(c) - 1
        start_grid[r][c] = m
        if m in {'x', 'o'}:
            assert r in free_rows and c in free_cols
            free_rows.remove(r)
            free_cols.remove(c)
        if m in {'+', 'o'}:
            assert r + c in free_sum and r - c in free_diff
            free_sum.remove(r + c)
            free_diff.remove(r - c)
    new_grid = [row[:] for row in start_grid]
    assert len(free_rows) == len(free_cols)
    for r, c in zip(free_rows, free_cols):
        # add vertical component x
        if new_grid[r][c] == '+':
            new_grid[r][c] = 'o'
        elif new_grid[r][c] == '.':
            new_grid[r][c] = 'x'
        else:
            assert False
    squares_by_sum, squares_by_diff = defaultdict(list), defaultdict(list)
    for r in range(N):
        for c in range(N):
            squares_by_sum[r + c].append((r,c))
            squares_by_diff[r - c].append((r,c))
    for i in range(2 * N - 1):
        squares_by_sum[i].sort(key=lambda p:len(squares_by_diff[p[0] - p[1]]))
    for i in range(- N + 1, N):
        squares_by_diff[i].sort(key=lambda p:len(squares_by_sum[p[0] + p[1]]))
    for s in sorted(range(2 * N - 1), key=lambda s:len(squares_by_sum[s])):
        if s not in free_sum: continue
        assert s in free_sum
        for p in reversed(squares_by_sum[s]):
            r, c = p
            assert r + c == s
            assert s in free_sum
            assert r + c in free_sum
            if r - c not in free_diff: continue
            # add diagonal component +
            if new_grid[r][c] == 'x':
                new_grid[r][c] = 'o'
            elif new_grid[r][c] == '.':
                new_grid[r][c] = '+'
            else:
                assert False
            # mark used
            free_sum.remove(r + c)
            free_diff.remove(r - c)
            break
    # Finish up
    score = 0
    changelist = []
    for r in range(N):
        for c in range(N):
            if new_grid[r][c] in {'x', 'o'}:
                score += 1
            if new_grid[r][c] in {'+', 'o'}:
                score += 1
            if new_grid[r][c] != start_grid[r][c]:
                changelist.append((r,c))
    print("Case #{}: {} {}".format(test_iteration, score, len(changelist)))
    for r,c in changelist:
        print(new_grid[r][c], r + 1, c + 1)

for i in range(1, int(input()) + 1):
    run_test(i)
