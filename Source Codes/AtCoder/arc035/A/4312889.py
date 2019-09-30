S = input()

for i in range(len(S) // 2):
    if S[i] == '*' or S[-(i+1)] == '*':
        continue
    elif S[i] != S[-(i+1)]:
        print('NO')
        break
else:
    print('YES')