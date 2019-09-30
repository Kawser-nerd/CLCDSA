import sys
import math

def is_prime(n):
    for x in range(2, int(math.sqrt(n))+1):
        if n % x == 0:
            #print "not prime: %d" % n
            return False
    return True


def count_sets(A, B, P):
    number_sets = {}
    for i in xrange(A, B+1):
        number_sets[i] = i

    for p in xrange(P, B-A):
      if is_prime(p):
        #print '\n%d: ' % p
        numbers = [n*p for n in xrange((A-1)/p+1, B/p+1)]
        #print numbers
        if len(numbers) > 1:
            the_set = min(number_sets[n] for n in numbers)
            for n in numbers:
                old_set = number_sets[n]
                number_sets[n] = the_set
                #ouch! 
                for k, v in number_sets.iteritems():
                    if v == old_set:
                        number_sets[k] = the_set
                    
            #print number_sets.values()

    return '%d' % len(set(number_sets.values()))

def do_one_test_case(file):
    A, B, P = [int(n) for n in file.readline().split()]

    return count_sets(A, B, P)

def main(argv):
    f = open(argv[1], 'r')
    cases = int(f.readline())
    output_list = []
    for i in xrange(cases):
        output_list.append('Case #%d: %s\n' % (i+1, do_one_test_case(f)))
    f.close()
    if len(argv) > 2:
        expected_f = open(argv[2], 'r')
        expected_list = expected_f.readlines()
        expected_list = [line.strip()+'\n' for line in expected_list[0:-1]]
        if (output_list == expected_list):
            print 'Everything matched!'
        else:
            print 'Actual: %s' % output_list
            print 'Expected: %s' % expected_list
    else:
        print ''.join(output_list)

def test():
    print 'Usage: scriptname.py infile [outfile]'
    print 'I\'ll run the doctests instead!'
    import doctest
    doctest.testmod()

if __name__ == "__main__":
    if len(sys.argv) < 2:
        test()
    else:
        main(sys.argv)
