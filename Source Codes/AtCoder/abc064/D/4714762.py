N = int(input())
S = input()

i = 0
c = 0
min_c = 0
while i < N:
    if S[i] == "(":
        c += 1
    else:
        c -= 1
    min_c = min(c, min_c)
    i += 1

print("(" * (-min_c) + S + ")" * (c-min_c))