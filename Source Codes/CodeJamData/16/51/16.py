from sys import stdin
import collections
import functools

DEBUG = False


def debug_print(*args):
    if DEBUG:
        print args

def main():
    num_cases = int(stdin.readline())
    for case in range(1, num_cases + 1):

        sched = list(stdin.readline().strip())
        l_sched = len(sched)

        tasks = []
        score = 0
        for i,s in enumerate(sched):
            if len(tasks) == l_sched - i:
                a = tasks.pop(-1)
                b = s
                if a == b:
                    score += 10
                else:
                    score += 5
            elif len(tasks) == 0:
                tasks.append(s)
            elif s == tasks[-1]:
                tasks.pop(-1)
                score += 10
            else:
                tasks.append(s)

        print "Case #{}: {}".format(case, score)

if __name__ == "__main__":
    main()
