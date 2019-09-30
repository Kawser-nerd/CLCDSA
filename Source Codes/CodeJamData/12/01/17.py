
map = {'a': 'y', 'c': 'e', 'b': 'h', 'e': 'o', 'd': 's', 'g': 'v',
       'f': 'c', 'i': 'd', 'h': 'x', 'k': 'i', 'j': 'u', 'm': 'l',
       'l': 'g', 'o': 'k', 'n': 'b', 'q': 'z', 'p': 'r', 's': 'n',
       'r': 't', 'u': 'j', 't': 'w', 'w': 'f', 'v': 'p', 'y': 'a',
       'x': 'm', 'z': 'q', ' ':' '}

# map = {' ': ' ', 'a': 'y', 'c': 'f', 'b': 'n', 'e': 'c', 'd': 'i',
#        'g': 'l', 'f': 'w', 'i': 'k', 'h': 'b', 'k': 'o', 'j': 'u',
#        'm': 'x', 'l': 'm', 'o': 'e', 'n': 's', 'q': 'z', 'p': 'v',
#        's': 'd', 'r': 'p', 'u': 'j', 't': 'r', 'w': 't', 'v': 'g',
#        'y': 'a', 'x': 'h', 'z': 'q'}

T = input()
for t in range(1,T+1):
    inp = raw_input()
    out = "".join([map[c] for c in inp])
    print "Case #" + str(t) + ": " + out
