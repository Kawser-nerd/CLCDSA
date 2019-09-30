'''
Created on May 6, 2012

@author: Lior
'''

import itertools

class DiamondFound(Exception):
    pass

def find_ancestors(class_num, inheritance, ancestors):
    if ancestors[class_num]:
        return
    direct_fathers = inheritance[class_num]
    ancestors[class_num].update(direct_fathers)
    for direct_father in direct_fathers:
        find_ancestors(direct_father, inheritance, ancestors)
        ancestors_of_direct_father = ancestors[direct_father]
        before = len(ancestors[class_num])
        ancestors[class_num].update(ancestors_of_direct_father)
        after = len(ancestors[class_num])
        if after-before != len(ancestors_of_direct_father):
            raise DiamondFound()
    
def solve(num_of_classes, inheritance):
    ancestors = dict((i, set()) for i in xrange(1, num_of_classes+1))
    for class_num in inheritance: # sort
        try:
            find_ancestors(class_num, inheritance, ancestors)
        except DiamondFound:
            return 'Yes'
    return 'No'
        
def process_files(in_file, out_file):
    num_of_test_cases = int(in_file.next().strip())
    for test_number in xrange(num_of_test_cases):
        num_of_classes = int(in_file.next().strip())
        inheritance = {}
        for class_num in xrange(1, num_of_classes+1):
            params = in_file.next().strip().split()
            assert len(params) - 1 == int(params[0])
            inheritance[class_num] = [int(i) for i in params[1:]]
        result = solve(num_of_classes, inheritance) 
        out_file.write('Case #%d: %s\n' % (test_number+1, result))

if __name__ == '__main__':
    with open('A-large.in', 'rb') as in_file:
        with open('A-large.out', 'wb') as out_file:
            process_files(in_file, out_file)
        