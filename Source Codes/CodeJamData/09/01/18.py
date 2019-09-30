from sys import stdin
from sys import stdout

def match(word, pattern):
    for i in xrange(len(word)):
        if word[i] not in pattern[i]:
            return False
    return True

line = stdin.readline()
parts = line.split()
L = int(parts[0])
D = int(parts[1])
N = int(parts[2])

dic = []
for i in xrange(D):
    line = stdin.readline()
    word = line.strip()
    dic.append(word)

for i in xrange(1, N + 1):
    line = stdin.readline()
    pattern = line.strip()
    ip = []
    j = 0
    while j < len(pattern):
        if pattern[j] == '(':
            p = pattern.index(')', j)
            s = frozenset(pattern[j + 1:p])
            j = p + 1
        else:
            s = frozenset(pattern[j])
            j += 1
        ip.append(s)
    c = 0
    for word in dic:
        if match(word, ip):
            c += 1
    stdout.write('Case #%d: %d\n' % (i, c))
