O = input()
E = input()
if len(O) == len(E):
    for i in range(len(O)):
        print(O[i] + E[i], end='')
else:
    for i in range(len(E)):
        print(O[i] + E[i], end='')
    print(O[-1:])