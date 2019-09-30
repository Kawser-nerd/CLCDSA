import sys
import math

def do_test(input):
    line = input.readline().split(' ')
    let_on_key = int(line[0])
    num_keys = int(line[1])
    num_let = int(line[2])
    line = input.readline().split(' ')
    freq = []
    for x in line:
        freq.append(int(x))

    freq.sort()
    sum = 0
    lets_used = 0
    keys_used = 0
    for x in reversed(freq):
        if keys_used == num_keys:
            keys_used = 0
            lets_used += 1
        sum += x*(lets_used+1)
        keys_used += 1
    return sum

input = sys.stdin

N = int(input.readline())

for test in range(N):
    answer = do_test(input)
    print 'Case #%(case)d: %(answer)d' % \
        {'case': test+1, 'answer': answer}
