import sys, itertools

def get_generators_up_to_length_n(n):
    generators = []
    for ii in range(1, n + 1):
        generators += get_generators_length_n(ii)
    return generators        

def get_generators_length_n(length):
    if length % 2 == 0: return get_even_generators_length_n(length)
    else: return get_odd_generators_length_n(length)

def get_odd_generators_length_n(length):
    if length == 1: return [1, 2, 3]
    else: 
        n = length / 2
        generators = []
        for ii in range(min(n, 4)):
            for comb in itertools.combinations(range(1, n), ii):
                first_half = ["1"] + ["0"] * (n-1)
                for jj in comb:
                    first_half[jj] = "1"
                second_half = list(first_half)
                second_half.reverse()
                palin = first_half + ["0"] + second_half
                generators.append(int("".join([elem for elem in palin])))
                palin[n] = "1"
                generators.append(int("".join([elem for elem in palin])))
                if ii <= 1:
                    palin[n] = "2"
                    generators.append(int("".join([elem for elem in palin])))
        generators.append(int("".join([elem for elem in (["2"] + ["0"] * (n - 1) + ["0"] + ["0"] * (n - 1) + ["2"])])))
        generators.append(int("".join([elem for elem in (["2"] + ["0"] * (n - 1) + ["1"] + ["0"] * (n - 1) + ["2"])])))
        generators.sort()
        return generators

def get_even_generators_length_n(length):
    if length == 2: return [11, 22]
    n = length / 2
    generators = []
    for ii in range(min(n, 4)):
        for comb in itertools.combinations(range(1, n), ii):
            first_half = ["1"] + ["0"] * (n-1)
            for jj in comb:
                first_half[jj] = "1"
            second_half = list(first_half)
            second_half.reverse()
            palin = first_half + second_half
            generators.append(int("".join([elem for elem in palin])))
    generators.append(int("".join([elem for elem in (["2"] + ["0"] * (length - 2) + ["2"])])))
    generators.sort()
    return generators

def is_palin(num):
    string = str(num)
    length = len(string)
    ii = 0
    while ii < length/2:
        if string[ii] != string[-(1+ii)]:
            return False
        ii += 1
    return True

def gen_fair_and_squares(upper_limit):
    fair_and_squares = []
    for ii in range(1, upper_limit + 1):
        if (is_palin(ii) and is_palin(ii*ii)):
            fair_and_squares.append(ii)
    return fair_and_squares

f = open(sys.argv[1])
T = int(f.readline())
gens = get_generators_up_to_length_n(60)
squares = map(lambda x: x*x, gens)

for t in range(T):
    A, B = map(int, f.readline().strip().split())
    total = 0
    for elem in squares:
        assert(is_palin(elem))
        if elem >= A and elem <= B: total += 1
        if elem > B:
            break

    print "Case #%d:" % (t + 1), total
