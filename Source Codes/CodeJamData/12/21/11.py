# -*- coding:utf-8 -*-
import os, math, cmath

curr_dir = os.path.dirname(os.path.abspath(__file__))
srcfilename = os.path.join(curr_dir, 'A-large.in')
dstfilename = os.path.join(curr_dir, 'output.txt')

def solve(numbers):
    results = []
    L = len(numbers)
    X = sum(numbers)
#    import ipdb; ipdb.set_trace()
    for index, number in enumerate(numbers):
        x = float(X)
        others = sorted(numbers[:index]+numbers[index+1:])
        others_min = [other_min for other_min in others if other_min <= number]
        l_min = len(others_min)
        others_max = [other_max for other_max in others if other_max > number]
        x -= sum([number-other_min for other_min in others_min])
        if x <= 0:
            results.append(0.)
        else:
            thresh = number
            solved = False
            for idx, other_max in enumerate(others_max):
                if (other_max-thresh)*(l_min+idx+1) < x:
                    x -= (other_max-thresh)*(l_min+idx+1)
                    thresh = other_max
                else:
                    final = thresh + float(x)/(l_min+idx+1)
                    results.append(float(final-number)/X)
                    solved = True
                    break
            if not solved:
                final = thresh + float(x)/L
                results.append(float(final-number)/X)
    results = [result*100. for result in results]
    return results

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
                results = solve(numbers)
                joined = ' '.join(['%3.8f' % result for result in results]) 
                outlines.append('Case #%d: %s\n' % (i+1, joined))
            outp.writelines(outlines)
