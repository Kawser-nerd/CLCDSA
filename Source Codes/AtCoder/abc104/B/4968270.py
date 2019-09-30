S = input()

if S[0] == 'A' and S[2:len(S)-1].count('C') == 1:
    for s in S[1:]:
        if s not in ('C') and s.isupper():
            print('WA')
            exit()
    print('AC')
else:
    print('WA')