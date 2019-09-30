ticket = list(str(input()))

for state in range(1 << (len(ticket)-1)):
    fomula = ticket[0] + ''.join(('+' if state >> i & 1 else '-') + x for i, x in enumerate(ticket[1:]))
    if eval(fomula) == 7:
        print(fomula + ''.join('=7'))
        exit()