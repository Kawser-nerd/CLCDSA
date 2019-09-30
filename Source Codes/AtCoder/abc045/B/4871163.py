Sa = input()
Sb = input()
Sc = input()

t = 'a'
while 1:

    if t == 'a':
        if len(Sa) == 0:
            winner = 'A'
            break
        t = Sa[0]
        Sa = Sa[1:]


    elif t == 'b':
        if len(Sb) == 0:
            winner = 'B'
            break
        t = Sb[0]
        Sb = Sb[1:]

    else:
        if len(Sc) == 0:
            winner = 'C'
            break
        t = Sc[0]
        Sc = Sc[1:]


print(winner)