f = open("input", "r")

test_cases = int(f.readline().strip())

for test_case in range(test_cases):
    a, b = (int(s) for s in f.readline().strip().split(" "))
    probabilities = [float(s) for s in f.readline().strip().split(" ")]
    
    assert(len(probabilities) == a)

    keystrokes_enter     = 2 + b
    keystrokes_backspace = {}
    
    prob_correct_so_far  = 1
    
    for i in range(a + 1):
        keys_if_correct_so_far = ((a - i) + (b - i)) + 1
        keys_if_incorrect_so_far = keys_if_correct_so_far + b + 1
        keystrokes_backspace[a - i] = (
            prob_correct_so_far * keys_if_correct_so_far +
            (1 - prob_correct_so_far) * (keys_if_incorrect_so_far))
    
        if i < a:
            prob_correct_so_far *= probabilities[i]
     
    print "Case #{}: {}".format(
            test_case + 1,
            min(keystrokes_backspace.values() + [keystrokes_enter]))

f.close()
