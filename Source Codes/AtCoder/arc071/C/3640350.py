def inpl(): return [int(i) for i in input().split()]

S = input()
T = input()
typeS = [0 for _ in range(1+len(S))]
typeT = [0 for _ in range(1+len(T))]
typeS[0] = typeT[0] = 0 
for i in range(len(S)):
    ctr = 2
    if S[i] == 'A':
        ctr = 1
    typeS[i+1] = (typeS[i] + ctr)%3
for i in range(len(T)):
    ctr = 2
    if T[i] == 'A':
        ctr = 1
    typeT[i+1] = (typeT[i] + ctr)%3
Q = int(input())
for _ in range(Q):
    a, b, c, d = inpl()
    if (typeS[b] - typeS[a-1])%3 == (typeT[d] -typeT[c-1])%3:
        print('YES')
    else:
        print('NO')