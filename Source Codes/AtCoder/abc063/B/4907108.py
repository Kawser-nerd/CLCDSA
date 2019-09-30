import collections
s = input()
c = collections.Counter(s)
if c.most_common(1)[0][1] != 1:
    print('no')
else:
    print('yes')