S = input()
l = len(S)
A = list(S)
flg = 0
if 'C' in A:
    C = A.index('C')
else:
    print('WA')
    flg = 1

if S[0] == 'A' \
and S[2:l-1].count('C') == 1 \
and S[1:C].islower() \
and S[C+1:].islower():
    print('AC')
else:
    if flg == 0:
        print('WA')