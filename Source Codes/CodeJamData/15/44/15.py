'''
cat test_d.txt | python problem_d.py
cat D-small-attempt3.in | python problem_d.py >D-small-attempt3.out
cat D-large.in | python problem_d.py >D-large.out
'''

from sys import stdin

def solve(table, c, last_was_3, rows_left, i3, i4, i6):
    if rows_left == 0:
        result = i3 * i4 * i6
        if i6 > 1:
            result /= 6
        elif i4 > 1:
            result /= 4
        elif i3 > 1:
            result /= 3
        return result
    result = table.get((last_was_3, rows_left, i3, i4, i6))
    if result is not None:
        return result
    result = 0
    if last_was_3:
        if rows_left >= 1:
            result += solve(table, c, not last_was_3, rows_left - 1, i3, i4, i6)
        if rows_left >= 2 and c % 3 == 0:
            result +=  solve(table, c, not last_was_3, rows_left - 2, i3*3, i4, i6)
        if rows_left >= 2 and c % 6 == 0:
            result +=  solve(table, c, not last_was_3, rows_left - 2, i3, i4, i6*6)
        if rows_left >= 3 and c % 4 == 0:
            result +=  solve(table, c, not last_was_3, rows_left - 3, i3, i4*4, i6)
    else:
        if rows_left >= 2:
            result +=  solve(table, c, not last_was_3, rows_left - 2, i3, i4, i6)
    result %= 1000000007
    table[(last_was_3, rows_left, i3, i4, i6)] = result
    return result

def main():
    tt = int(stdin.readline().strip())
    for t in xrange(1, tt+1):
        (r, c) = (int(s) for s in stdin.readline().strip().split(' '))
        table = dict()
        a = solve(table, c, True, r, 1, 1, 1)
        b = solve(table, c, False, r, 1, 1, 1)
        result = (a + b) % 1000000007
        print "Case #{}: {}".format(t, result)

main()
