import sys

def read_pattern(pattern_as_str, word_len):
    pattern = []
    inside_group = False
    for c in pattern_as_str:
        if c == '(':
            assert not inside_group
            inside_group = True
            pattern.append([])
        elif c == ')':
            assert inside_group
            inside_group = False
        else:
            if inside_group:
                pattern[-1].append(c)
            else:
                pattern.append([c])
    assert len(pattern) == word_len
    return pattern

def match_pattern(pattern, word):
    assert len(pattern) == len(word)
    for pe, c in zip(pattern, word):
        if c not in pe:
            return False
    return True

def solve_case(in_fp, alien_dict, word_len):
    pattern_as_str = in_fp.readline().strip()
    pattern = read_pattern(pattern_as_str, word_len)
    
    matches_count = 0
    for aw in alien_dict:
        if match_pattern(pattern, aw):
            matches_count += 1
    
    return str(matches_count)

def main(argv):
    sys.setrecursionlimit(100000)
    
    in_fp = open(argv[1], 'rb')
    out_fp = open(argv[2], 'wb')

    word_len, dict_size, num_cases = map(int, in_fp.readline().split())
    alien_dict = []
    for i in range(dict_size):
        alien_dict.append(in_fp.readline().strip())
        assert len(alien_dict[-1]) == word_len
    for i in range(num_cases):
        solution = solve_case(in_fp, alien_dict, word_len)
        out_fp.write('Case #%d: %s\n' % (i+1, solution))
    
    in_fp.close()
    out_fp.close()

if __name__ == '__main__':
    main(sys.argv)
