N, Q = map(int, input().split())
S = input()

AC_appearance = [0] * len(S)
counter = 0
for i in range(1, len(S)):
    if S[i-1] == 'A' and S[i] == 'C':
        counter += 1
    AC_appearance[i] = counter 

for i in range(Q):
    l, r = map(int, input().split())
    l = l - 1
    r = r - 1
    print(AC_appearance[r] - AC_appearance[l])