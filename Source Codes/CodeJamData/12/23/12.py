# -*- coding:utf-8 -*-
import os, itertools

curr_dir = os.path.dirname(os.path.abspath(__file__))
srcfilename = os.path.join(curr_dir, 'C-large.in')
dstfilename = os.path.join(curr_dir, 'output.txt')

def solve(numbers_):
    numbers = sorted(numbers_)
    memory = dict((k, [k]) for k in numbers)
    for r in xrange(2, len(numbers)):
        combinations = itertools.combinations(numbers, r)
        for combination in combinations:
            s = sum(combination)
            if s in memory:
                r1 = memory[s]
                r2 = combination
                return r1, r2
            memory[s] = combination
    return 'Impossible'

if __name__ == '__main__':
    with open(srcfilename, 'rb') as inp:
        with open(dstfilename, 'wb') as outp:
            lines = inp.readlines()
            count = int(lines.pop(0))
            outlines = []
            for i in xrange(count):
                line = lines[i]
                numbers = [int(number) for number in line.split(' ')]
                numbers.pop(0)
                result = solve(numbers)
                if result == 'Impossible':
                    outlines.append('Case #%d: Impossible\n' % (i+1,))
                else:
                    r1, r2 = result
                    outlines.append('Case #%d:\n' % (i+1,))
                    outlines.append('%s\n' % ' '.join(['%d' % r1i for r1i in r1]))
                    outlines.append('%s\n' % ' '.join(['%d' % r2i for r2i in r2]))
            outp.writelines(outlines)
