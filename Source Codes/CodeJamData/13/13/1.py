#!pypy
import multiprocessing
import os
import sys
import cPickle
from collections import defaultdict

def _pmap_worker_func(f, q, results):
    while True:
        work = q.get()
        if work is None:
            q.task_done()
            return

        i, a = work
        try:
            r = f(a)
            print >>sys.stderr, i
            results.put((i, r))
        except:
            import traceback
            traceback.print_exc()
        q.task_done()

def parallel_map(f, args, num_procs=8):
    procs = []
    q = multiprocessing.JoinableQueue()
    results = multiprocessing.Queue()
    while len(procs) < num_procs:
        p = multiprocessing.Process(target=_pmap_worker_func, args=(f, q, results))
        procs.append(p)
        p.daemon = True
        p.start()

    for i, a in enumerate(args):
        q.put((i, a))
    # add shutdown commands:
    for i in xrange(num_procs):
        q.put(None)

    q.join()

    assert results.qsize() == len(args)
    results_dict = {}
    for i in xrange(len(args)):
        idx, r = results.get()
        results_dict[idx] = r

    rtn = []
    for i in xrange(len(args)):
        r = results_dict[i]
        rtn.append(r)

    return rtn

possibilities = []
def gen_all(l, idx, minval):
    if idx == len(l):
        # print l
        possibilities.append(list(l))
        return
    for i in xrange(minval, M+1):
        l[idx] = i
        gen_all(l, idx+1, i)

def fact(n):
    if n <= 2:
        return n
    return n * fact(n-1)

def occurrences(nums):
    nom = fact(len(nums))

    counts = defaultdict(int)
    for n in nums:
        counts[n] += 1
    for v in counts.values():
        nom /= fact(v)
    return nom

if __name__ == "__main__":
    f = sys.stdin
    if len(sys.argv) >= 2:
        fn = sys.argv[1]
        if fn != '-':
            f = open(fn)

    GEN = True

    T = int(f.readline())
    for _T in xrange(T):
        R, N, M, K = map(int, f.readline().split())
        gen_all([0]*N, 0, 2)

        print "Case #1:"

        fn = "%d%d.pkl" % (N, M)
        if not os.path.exists(fn):
            product_counts = []
            for nums in possibilities:
                if nums[-1] == 7:
                    print nums
                products = defaultdict(int)
                for bitmask in xrange(2**N):
                    product = 1
                    bad = False
                    for i in xrange(N):
                        if bitmask & (2**i):
                            product *= nums[i]
                        else:
                            minv = nums[i]+1
                    products[product] += 1
                product_counts.append(dict(products))
            cPickle.dump(product_counts, open(fn, 'w'))
        else:
            product_counts = cPickle.load(open(fn))

        # print zip(possibilities, product_counts)
        # print len(product_counts)

        def calc(products):
            assert len(products) == K
            best = 0
            best_idx = -1
            for i in xrange(len(possibilities)):
                cur = occurrences(possibilities[i])
                pc = product_counts[i]
                for p in products:
                    if p not in pc:
                        break
                    cur *= pc[p]
                else:
                    if cur > best:
                        best = cur
                        best_idx = i

            assert best
            assert best_idx >= 0
            return ''.join(map(str, possibilities[best_idx]))

        test_cases = []
        for _r in xrange(R):
            products = map(int, f.readline().split())
            test_cases.append(products)
        # results = map(calc, test_cases)
        results = parallel_map(calc, test_cases)
        for r in results:
            print r

            # print products
            # print best
            # print


