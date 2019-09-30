# pylint: disable=missing-docstring
import sys
import math


def problem(pancakes, order_size):
    pancakes.sort(key=lambda x: 2 * math.pi * x[0] * x[1], reverse=True)

    take = pancakes[:order_size - 1]
    if len(take) != 0:
        max_radius = max(x[0] for x in take)
    else:
        max_radius = 0
    outsides = sum(2 * math.pi * x[0] * x[1] for x in take)

    best = 0
    for n in pancakes[order_size - 1:]:
        radius = max(max_radius, n[0])
        size = outsides + 2 * math.pi * n[0] * n[1] + math.pi * radius * radius
        best = max(best, size)

    return best


def nextline(input_file):
    data = ""
    while not data:
        data = input_file.readline()
    return data[:-1]

def intsplit(s):
    return [int(x) for x in s.split(" ")]


def main():
    result = ""
    with sys.stdin if len(sys.argv) == 1 else open(sys.argv[1], 'r') as infile:
        number = int(nextline(infile))
        for run in range(number):
            case = nextline(infile)
            size, order_size = intsplit(case)
            pancakes = []
            for _ in range(size):
                pancakes.append(intsplit(nextline(infile)))
            result += 'Case #{}: {}\n'.format(1 + run, problem(pancakes, order_size))

    if len(sys.argv) == 1:
        print(result, end='')
    else:
        with open(sys.argv[1].replace('in', 'sol'), 'w') as result_file:
            result_file.write(result)

if __name__ == '__main__':
    main()
