# -*- coding: utf-8 -*-

h, w = map(int, input().split())

a = [list(input()) for i in range(h)]

# ???????????????????????????????

a_new = list()

for i, li  in enumerate(a):
    if a[i].count('.')  != w:
        a_new.append(a[i])

b = [list(i) for i in zip(*a_new)]


b_new = list()

for i, li  in enumerate(b):
    if b[i].count('.')  != len(b[0]):
        b_new.append(b[i])

c = [list(i) for i in zip(*b_new)]
for i in c:
    print(''.join(i))