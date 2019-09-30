sample_in = """y qee
ejp mysljylc kd kxveddknmc re jsicpdrysi
rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd
de kr kd eoya kw aej tysr re ujdr lkgc jv
"""
sample_out = """a zoo
our language is impossible to understand
there are twenty six factorial possibilities
so it is okay if you want to just give up
"""
key = {}
keys = set()
values = set()
assert len(sample_in) == len(sample_out)
for i, ch in enumerate(sample_in):
    key[ch] = sample_out[i]
    keys.add(ch)
    values.add(sample_out[i])
alpha = set([chr(i) for i in range(ord('a'), ord('z') + 1)])
nonkeys = alpha - keys
if nonkeys:
    assert len(nonkeys) == 1
    nonvalues = alpha - values
    assert len(nonvalues) == 1
    key[nonkeys.pop()] = nonvalues.pop()
import sys
for num, line in enumerate(sys.stdin):
    if not num: continue
    print "Case #" + str(num) + ": " + ''.join([key[c] for c in line.strip()])
