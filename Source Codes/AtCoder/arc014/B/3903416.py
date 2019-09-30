N = int(input())
S = [input() for i in range(N)]

before = S[0][-1]
rule_break_flag = False
for i in range(1, N):
    if S[i] in S[:i] or before != S[i][0]:
        rule_break_flag = True
        break
    before = S[i][-1]

if rule_break_flag:
    if i % 2 != 0:
        print('WIN')
    else:
        print('LOSE')
else:
    print('DRAW')