# -*- coding: utf-8 -*-

m = input()

word = [w for w in m if w not in ["a", "i", "u", "e", "o"]]


for w in word:
    print(w, end="")
print()