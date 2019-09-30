s = list(input())
t = list(input())

atc = list('atcoder@')

for i in range(len(s)):
    if s[i] == '@' and t[i] in atc:
        continue
    elif t[i] == '@' and s[i] in atc:
        continue
    elif s[i] == t[i]:
        continue
    else:
        print('You will lose')
        exit()

print('You can win')