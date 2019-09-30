s = input()
print('No' if len([x for x in [[s.count('N'), s.count('S')], [s.count('W'), s.count('E')]] if x.count(0) == 1]) else 'Yes')