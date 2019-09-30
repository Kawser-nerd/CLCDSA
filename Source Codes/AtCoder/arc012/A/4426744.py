l = ['Sunday', 'Monday', 'Tuesday', 'Wednesday', 'Thursday', 'Friday', 'Saturday'][::-1]
s = input()
if s == 'Sunday':
    print(0)
else:
    print(l.index(s))