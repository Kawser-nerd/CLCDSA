def is_ugly(n):
    return n % 2 == 0 or n % 3 == 0 or n % 5 == 0 or n % 7 == 0

def add_expr(expr_dict, expr, n_e):
    n = expr_dict.get(expr, 0)
    expr_dict[expr] = n + n_e

def solve(digits):
    # expressions = set([(None, digits[0])])
    expressions = {}
    expressions[(None, digits[0])] = 1
    if len(digits) > 1:
        for d in digits[1:]:
            # new_expressions = set()
            new_expressions = {}
            for e, n_e in expressions.items():
                # new_expressions.add(e[0], e[1] + d))
                add_expr(new_expressions, (e[0], e[1] + d), n_e)
                i = int(e[1])
                if e[0] != None:
                    # new_expressions.add((e[0] + i, d))
                    add_expr(new_expressions, (e[0] + i, d), n_e)
                    # new_expressions.add((e[0] - i, d))
                    add_expr(new_expressions, (e[0] - i, d), n_e)
                else:
                    # new_expressions.add((i, d))
                    add_expr(new_expressions, (i, d), n_e)
                expressions = new_expressions
    n_ugly = 0
    for e, n_e in expressions.items():
        i = int(e[1])
        if e[0] != None:
            if is_ugly(e[0] + i):
                n_ugly += n_e
            if is_ugly(e[0] - i):
                n_ugly += n_e
        else:
            if is_ugly(i):
                assert(n_e == 1)
                n_ugly += n_e
    return n_ugly

if __name__ == '__main__':
    N = input()
    for i in xrange(N):
        digits = raw_input()
        print 'Case #%d: %d' % (i + 1, solve(digits))
