S = input()

if S[0] == 'A':
    f1 = True
else:
    f1 = False

C_cnt = 0
for s in S[2:-1]:
    if s == 'C':
        C_cnt += 1
if C_cnt == 1:
    f2 = True
else:
    f2 = False

f3 = True
for s in S:
    if s == 'A' or s == 'C':
        continue
    if s != s.lower():
        f3 = False
        break

if f1 and f2 and f3:
    print('AC')
else:
    print('WA')