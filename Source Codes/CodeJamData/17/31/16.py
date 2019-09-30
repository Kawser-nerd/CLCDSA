import argparse
import math

def max_sides(pancakes, k):
    p2 = pancakes
    base = p2[0]
    p2 = p2[1:]
    sorted_p2 = sorted(p2, key=lambda p: p[1], reverse=True)
    # print "sorted p2", sorted_p2

    ps = sorted_p2[:k-1] + [base]
    # print "ps", ps
    sum = 0
    for p in ps:
        sum += p[1]

    return sum

def main(f_in, f_out):

    num_cases = int(f_in.readline().strip())
    for case in range(1, num_cases+1):
        n, k = f_in.readline().strip().split()
        n = int(n)
        k = int(k)

        # list (r, side surface area)
        pancakes = []

        for pancake in range(n):
            r, h = f_in.readline().strip().split()
            r = int(r)
            h = int(h)

            pancakes += [(r, 2 * math.pi * r * h)]

        # print pancakes

        # widest to narrowest
        sorted_pancakes = sorted(pancakes, key=lambda p: p[0], reverse=True)
        # print "sorted", sorted_pancakes

        best_total = 0
        for start_pancake in range(0, n-k+1):
            # print "start", start_pancake, sorted_pancakes[start_pancake:]
            s = max_sides(sorted_pancakes[start_pancake:], k)

            r = sorted_pancakes[start_pancake][0]
            top = math.pi * r * r
            # print "r, top", r, top
            # print "s", s

            best_total = max(best_total, s + top)
            # print "got", s + top

        f_out.write('Case #{}: {:.8f}\n'.format(case, best_total))

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
