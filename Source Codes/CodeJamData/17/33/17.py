import argparse

def solve(n, k, u, ps):
    if k < n:
        raise Exception("k < n, whoa")
    # train everything to the max
    if u + sum(ps) >= n:
        return 1

    sorted_ps = sorted(ps)

    num_to_raise = 1

    while u > 0.0000001:
        print n, sorted_ps, num_to_raise, u
        if num_to_raise == n:
            max_to_raise = 1.0
        else:
            max_to_raise = sorted_ps[num_to_raise] - sorted_ps[num_to_raise - 1]

        amt_to_add = min (u * 1.0 / num_to_raise, max_to_raise)
        for pi in range(0, num_to_raise):
            sorted_ps[pi] += amt_to_add
            u -= amt_to_add

        num_to_raise += 1

    final = reduce(lambda x, y: x*y, sorted_ps)
    return final


def main(f_in, f_out):

    num_cases = int(f_in.readline().strip())
    for case in range(1, num_cases+1):
        n, k = f_in.readline().strip().split()
        n = int(n)
        k = int(k)
        u = float(f_in.readline().strip())
        ps = [float(p) for p in f_in.readline().strip().split()]
        
        solution = solve(n, k, u, ps)
 
        f_out.write('Case #{}: {:.8f}\n'.format(case, solution))

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('infile')

    opts = parser.parse_args()
    infile = opts.infile
    outfile = infile.split('.')[0]+'.out'
    print "Solving! in: {} -> out: {}".format(infile, outfile)

    with open(infile, 'r') as f_in:
        with open(outfile, 'w') as f_out:
            main(f_in, f_out)
