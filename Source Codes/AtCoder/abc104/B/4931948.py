S = input()

if S[0] == 'A' and S[2:-1].count('C') == 1:
    if S.replace('A', '').replace('C', '').islower():
        print('AC')
    else:
        print('WA')
else:
    print('WA')