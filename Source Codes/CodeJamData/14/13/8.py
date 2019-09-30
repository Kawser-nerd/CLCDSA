import random, math, pickle, os, time

N = 1000
trials = 100000 #100k is good
cases = 120
data_file = 'probs.pkl'

def bad_shuffle():
    """Returns a bad shuffle of a list of 1000 numbers.
    """
    nums = list(range(N))
    for i in range(N):
        randint = random.randrange(N)
        swap = nums[i]
        nums[i] = nums[randint]
        nums[randint] = swap

    return nums

def good_shuffle():
    nums = list(range(N))
    random.shuffle(nums)
    return nums

def profile_good_shuffles():
    occurrences = [list([1.0 / N] * N) for _ in range(N)]
    return occurrences

def profile_bad_shuffles(trials):
    """Finds the chance that each number 0...999 appears
    in a particular spot in a bad shuffle.
    
    occurrences[i][n] is the number of times that N
    appeared in slot I.
    """
    occurrences = [list([0] * N) for _ in range(N)]

    for _ in range(trials):
        lst = bad_shuffle()
        for i in range(N):
            occurrences[i][lst[i]] += 1

    #Normalize
    for i in range(len(occurrences)):
        occurrences[i] = [float(x)/trials for x in occurrences[i]]

    return occurrences

def logify(table):
    """Takes the log of all elements in a 2D table.
    """
    for i in range(len(table)):
        table[i] = [math.log(max(x, 0.0001)) for x in table[i]]
    return table

def probability(lst, probs):
    """Given a table of log probabilities where
    probs[i][n] = log(probability of N appearing in slot I),
    gives the probability of generating LST.
    """
    probability = 0
    for i in range(N):
        probability += probs[i][lst[i]]
    return probability

def stringify(lst):
    return [str(i) for i in lst]

def gen_test():
    output = 'Blah\n'
    for _ in range(50):
        output += '1000\n'
        output += ' '.join(stringify(bad_shuffle())) + '\n'
    for _ in range(50):
        output += '1000\n'
        output += ' '.join(stringify(good_shuffle())) + '\n'

    with open('test.in', 'w') as f:
        f.write(output)

def main():
    start = time.clock()
    bad_probs = logify(profile_bad_shuffles(trials))
    print "Time taken: %s" % (time.clock() - start)
    good_probs = logify(profile_good_shuffles())

    output = ''
    with open('test.in') as f:
        f.readline()
        case_probs = []
        for case in range(cases):
            f.readline()
            lst = [int(i) for i in f.readline()[:-1].split()]

            bp = probability(lst, bad_probs)
            case_probs.append((case, bp))
        case_probs.sort(key = lambda c_p: c_p[1])
        bad_judgements = [case for case, p in case_probs[:cases / 2]]

        for case in range(cases):
            if case in bad_judgements:
                ans = 'GOOD'
            else:
                ans = 'BAD'
            out_line = 'Case #%s: %s\n' % (case + 1, ans)
            output += out_line

    with open('test.out', 'w') as f:
        f.write(output)

#gen_test()
main()