# pylint: disable=missing-docstring
import sys


def problem(cameron, jamie):
    cameron.sort(reverse=True)
    jamie.sort(reverse=True)
    cb_blocks = []
    jb_blocks = []
    c_time = 0
    j_time = 0
    c_switch_time = 0
    j_switch_time = 0
    if (not jamie) or (cameron and cameron[0][0] > jamie[0][0]):
        last = "c"
        last_end_time = -1440 + cameron[0][1]
    else:
        last = "j"
        last_end_time = -1440 + jamie[0][1]
    switches = 0

    while True:
        if not cameron and not jamie:
            break
        if (not jamie) or (cameron and cameron[-1][0] < jamie[-1][0]):
            if last == "c":
                cb_blocks.append(cameron[-1][0] - last_end_time)
            else:
                c_switch_time += cameron[-1][0] - last_end_time
                switches += 1
            c_time += cameron[-1][1] - last_end_time
            last = "c"
            last_end_time = cameron[-1][1]
            del cameron[-1]
        else:
            if last == "j":
                jb_blocks.append(jamie[-1][0] - last_end_time)
            else:
                j_switch_time += jamie[-1][0] - last_end_time
                switches += 1
            j_time += jamie[-1][1] - last_end_time
            last = "j"
            last_end_time = jamie[-1][1]
            del jamie[-1]

    if c_time > j_time:
        j_time += c_switch_time
        if j_time >= 720:
            return switches
        cb_blocks.sort(reverse=True)
        for i in cb_blocks:
            j_time += i
            switches += 2
            if j_time >= 720:
                return switches
    else:
        c_time += j_switch_time
        if c_time >= 720:
            return switches
        jb_blocks.sort(reverse=True)
        for i in jb_blocks:
            c_time += i
            switches += 2
            if c_time >= 720:
                return switches



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
            ac, aj = intsplit(case)
            acs = []
            ajs = []
            for _ in range(ac):
                acs.append(intsplit(nextline(infile)))
            for _ in range(aj):
                ajs.append(intsplit(nextline(infile)))
            result += 'Case #{}: {}\n'.format(1 + run, problem(acs, ajs))

    if len(sys.argv) == 1:
        print(result, end='')
    else:
        with open(sys.argv[1].replace('in', 'sol'), 'w') as result_file:
            result_file.write(result)

if __name__ == '__main__':
    main()
