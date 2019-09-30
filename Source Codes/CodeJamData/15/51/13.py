
def parse(line1, line2, line3):
    n, d, s, a_s, c_s, r_s, m, a_m, c_m, r_m = map(int, line1.split() +
                                                     line2.split() +
                                                     line3.split())
    salaries = {0: s}
    managees = {0: set()}
    for i in range(1, n):
        s = (s * a_s + c_s) % r_s
        m = (m * a_m + c_m) % r_m
        salaries[i] = s
        managees[i] = set()
        managees[m % i].add(i)
    return (d, salaries, managees)

def solve(*args):
    d, salaries, managees = parse(*args)
    return save_employees(d, salaries, managees)

def legal_employees(salaries, managees, ub, lb, root=0):
    def safe(i):
        return salaries[i] <= ub and salaries[i] >= lb
    if not safe(root):
        return 0
    else:
        return 1 + sum([legal_employees(salaries, managees, ub, lb, i)
                        for i in managees[root]])

def save_employees(d, salaries, managees):
    min_lb = max(0, salaries[0] - d)
    return max([legal_employees(salaries, managees, lb + d, lb)
                for lb in range(min_lb, salaries[0] + 1)])

def run():
    with open('A.in') as infile:
        with open('A.out', 'w') as outfile:
            ncases = int(infile.next())
            for i in range(ncases):
                line1 = infile.next()
                line2 = infile.next()
                line3 = infile.next()
                outfile.write("Case #%s: %s\n" % (i+1,
                                                  solve(line1, line2, line3)))

