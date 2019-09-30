# -*- coding utf-8 -*-

w = str(input())
h = set(w)

for i in h:
    if w.count(i)%2 != 0:
        print("No")
        exit()


print("Yes")