import sys

def concat_str(args):
    s = " "
    for arg in args:
        s += str(arg)
    return s

def debug(*args):
    sys.stderr.write(concat_str(args) + "\n")

def printf(*args):
    debug(*args)
    print concat_str(args)

def int_input():
    return map(int, raw_input().split(' '))


#######################################################


def read_input():
    N = int(raw_input())
    vines = []
    for i in range(N):
        vines.append(int_input())
    D = int(raw_input())
    vines.sort()
    return N, D, vines


def solve(N, D, vines):
    max_grab = [0 for i in range(N)]
    max_grab[0] = vines[0][0]
    
    for i in range(N):
        vine = vines[i]
        length = max_grab[i]


        if vine[0] + length >= D:
            return "YES" 

        if length == 0:
            return "NO"

        for j in range(i+1, N):
            distance = vines[j][0] - vine[0]
            if vines[j][0] - vine[0] <= length:
                grabbed_size = min(distance, vines[j][1])
                max_grab[j] = max(max_grab[j], grabbed_size)

    return "NO"


#######################################################


for n_test_case in range(1, int(raw_input()) + 1):
    debug("Solving case ", n_test_case)

    printf("Case #", n_test_case, ": ", str(solve(*read_input())))

