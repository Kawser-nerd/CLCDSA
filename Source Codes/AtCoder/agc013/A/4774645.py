n = int(input())
s = map(int, input().split())
s = list(s)
num = 0
ASC, DES, EQ, UND = 0, 1, 2, 3
state = UND
if len(s) <= 2:
    print(1)
    exit()
i = s[0]
for j in s[1:]:
    if state == UND:
        if i > j:
            state = DES
        elif i < j:
            state = ASC
        else:
            state = EQ
        num += 1
    elif state == EQ:
        if i > j:
            state = DES
        elif i < j:
            state = ASC
    elif state == DES:
        if i >= j:
            pass
        else:
            state = UND
    else:
        if i <= j:
            pass
        else:
            state = UND
    i = j
if state == UND:
    num += 1

print(num)