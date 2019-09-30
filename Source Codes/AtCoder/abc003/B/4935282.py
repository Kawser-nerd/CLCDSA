# -*- coding: utf-8 -*-

S = input()
T = input()

lll = ["a", "t", "c", "o", "d", "e", "r"]

if S == T:
    print("You can win")
    exit()

if "@" not in S and "@" not in T:
    print("You will lose")
    exit()

for i, w in enumerate(S):
    if "@" == w:
        r = T[i]
        if r not in lll:
            if "@" == r:
                continue
            else:
                print("You will lose")
                exit()
    else:
        if w == T[i]:
            continue
        else:
            if T[i] == "@":
                continue
            else:
                print("You will lose")
                exit()

for i, w in enumerate(T):
    if "@" == w:
        r = S[i]
        if r not in lll:
            if "@" == r:
                continue
            else:
                print("You will lose")
                exit()
    else:
        if w == S[i]:
            continue
        else:
            if S[i]=="@":
                continue
            else:
                print("You will lose")
                exit()

print("You can win")