# pylint: disable=missing-docstring
import sys


def problem(success, units, cores):
    cores.sort()
    cores.append(1.0)
    spent = 0.0
    min_prob = 0.0

    for i, core in enumerate(cores):
        if core == 1.0:
            min_prob = 1.0
            break
        plan = (cores[i+1] - cores[i]) * (i + 1)
        if plan > units - spent:
            min_prob = core + (units - spent) / (i + 1)
            break
        spent += plan

    prob = 1.0
    for n in cores:
        prob *= max(min_prob, n)
    return prob


def nextline(input_file):
    data = ""
    while not data:
        data = input_file.readline()
    return data[:-1]

def intsplit(s):
    return [int(x) for x in s.split(" ")]

def floatsplit(s):
    return [float(x) for x in s.split(" ")]


def main():
    result = ""
    with sys.stdin if len(sys.argv) == 1 else open(sys.argv[1], 'r') as infile:
        number = int(nextline(infile))
        for run in range(number):
            case = nextline(infile)
            total, success = intsplit(case)
            units = float(nextline(infile))
            cores = floatsplit(nextline(infile))
            result += 'Case #{}: {}\n'.format(1 + run, problem(success, units, cores))

    if len(sys.argv) == 1:
        print(result, end='')
    else:
        with open(sys.argv[1].replace('in', 'sol'), 'w') as result_file:
            result_file.write(result)

if __name__ == '__main__':
    main()
