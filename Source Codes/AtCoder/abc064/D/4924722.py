N = int(input())
S = input()

l_cnt = 0
for s in S[::-1]:
    if s == ')':
        l_cnt += 1
    elif s == '(':
        if l_cnt != 0:
            l_cnt -= 1

r_cnt = 0
for s in S:
    if s == '(':
        r_cnt += 1
    elif s == ')':
        if r_cnt != 0:
            r_cnt -= 1
            
print('(' * l_cnt + S + ')' * r_cnt)