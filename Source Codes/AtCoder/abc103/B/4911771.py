# -*- coding: utf-8 -*-


s = input()
t = input()
i = 0
count = 0

while i < len(s):
    s = list(s)
    a = s.pop(0)
    s.append(a)
    s = ''.join(s)

    if s == t:
        count += 1

    i += 1


if count >= 1:
    print('Yes')
else:
    print('No')