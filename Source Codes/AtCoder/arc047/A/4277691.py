N,L = map(int,input().split(" "))
S = str(input())
T = 1
C = 0
for i in range(N):
    if S[i] == "+":
        T += 1
    elif S[i] == "-":
        T -= 1

    if T > L:
        C += 1
        T = 1
print(C)