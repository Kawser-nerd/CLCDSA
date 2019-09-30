import sys, itertools
data = filter(None, map(lambda x:x.strip(), open(sys.argv[1]).readlines()))

def pop_int(data):
    return int(data.pop(0))

def pop_ints(data):
    return map(int, data.pop(0).split())

def pop_rows(data, num_rows):
    result = data[:num_rows]
    for i in range(num_rows):
        data.pop(0)
    return result

def pop_case(data):
    num_cards = pop_int(data)
    indices = pop_ints(data)[1:]
    return num_cards, indices

def make_deck(num_cards):
    deck = [None for i in range(num_cards)]
    indices_open = range(num_cards)
    last_ii = 0
    for i in range(1, num_cards+1):
        #print "indices open:", indices_open
        #print "index_index = (%d + %d - 1) mod %d" % (i, last_ii, len(indices_open))
        last_ii = index_index = (i + last_ii - 1) % len(indices_open)
        position = indices_open[index_index]
        #print "Setting %d to %d" % (position, i)
        assert(deck[position] is None)
        deck[position] = i
        indices_open.remove(position)
    return deck

def solve(num_cards, indices):
    solution = make_deck(num_cards)
    answer = ' '.join(str(solution[i - 1]) for i in indices)
    return answer
    
    
num_cases = pop_int(data)
for case_num in range(1, num_cases+1):
    num_cards, indices = pop_case(data)
    answer = solve(num_cards, indices)
    print "Case #%d: %s" % (case_num, answer)
