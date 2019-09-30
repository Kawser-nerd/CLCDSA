# -*- coding:utf-8 -*-
w = input()

while w != "":
    if w.count(w[0]) % 2 == 0:
        w = w.replace(w[0], '')
    else:
        print("No")
        exit()
print("Yes")