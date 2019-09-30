S = input()

if S[0] == 'A' and S[2:-1].count('C') == 1:
    c = S.index('C')
    if S[1:c].islower() and S[c+1:].islower():
        print('AC')
        exit()


print('WA')