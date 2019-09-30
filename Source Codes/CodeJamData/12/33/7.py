'''
Created on May 6, 2012

@author: Lior
'''

from copy import deepcopy

def compact(boxes, toys):
    if boxes[0][0] == 0:
        boxes.pop(0)
    if toys[0][0] == 0:
        toys.pop(0)
    
def solve(boxes, toys, M=None):
    if M is None:
        M = {} 
    if len(boxes) == 0 or len(toys) == 0:
        return 0
    key = (len(boxes), len(toys), boxes[0][0], toys[0][0])
    if key in M:
        return M[key]
    if boxes[0][1] == toys[0][1]:
        # matching types!
        matches = min(boxes[0][0], toys[0][0])
        boxes = [[boxes[0][0]-matches, boxes[0][1]]]+boxes[1:]
        toys = [[toys[0][0]-matches, toys[0][1]]]+toys[1:]
        compact(boxes, toys)
        M[key] = matches+solve(boxes, toys, M)
        return M[key]
    # not matching types!
    # we have two options: discarding all the boxes or all the toys from this type
    M[key] = max(solve(boxes[1:], toys, M), solve(boxes, toys[1:], M))
    return M[key]

def process_files(in_file, out_file):
    num_of_test_cases = int(in_file.next().strip())
    for test_number in xrange(num_of_test_cases):
        N, M = [int(i) for i in in_file.next().strip().split()]
        boxes_raw = in_file.next().strip().split()
        boxes = []
        for i in xrange(len(boxes_raw)/2):
            boxes.append([int(boxes_raw[2*i]), int(boxes_raw[2*i+1])])
        toys_raw = in_file.next().strip().split()
        toys = []
        for i in xrange(len(toys_raw)/2):
            toys.append([int(toys_raw[2*i]), int(toys_raw[2*i+1])])
        assert len(boxes) == N
        assert len(toys) == M
        result = solve(boxes, toys)
        out_file.write('Case #%d: %s\n' % (test_number+1, result))

if __name__ == '__main__':
    with open('C-large.in', 'rb') as in_file:
        with open('C-large.out', 'wb') as out_file:
            process_files(in_file, out_file)
        