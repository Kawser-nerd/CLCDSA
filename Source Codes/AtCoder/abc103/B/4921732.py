S = input()
T = input()
flg = 0
for i in range(len(S)):
    S = S[-1:] + S[:len(S)-1]
    if S == T:
        flg = 1
if flg == 1:
    print('Yes')
else:
    print('No')