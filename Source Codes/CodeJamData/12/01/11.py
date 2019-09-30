A = "ejpmysljylckdkxveddknmcrejsicpdrysirbcpcypcrtcsradkhwyfrepkymveddknkmkrkcddekrkdeoyakwaejtysrreujdrlkgcjv"
B = "ourlanguageisimpossibletounderstandtherearetwentysixfactorialpossibilitiessoitisokayifyouwanttojustgiveup"

d = dict(zip(A, B))
d['z'] = 'q'
d['q'] = 'z'
d[' '] = ' '

T = input()
for t in range(T):
    s = raw_input()
    print 'Case #%d: %s' % (t + 1, ''.join(map(lambda x: d[x], s)))
