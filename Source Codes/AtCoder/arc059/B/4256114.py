S = list(input())
S.append("A")
for j in range(len(S) - 2):
    if (S[j] == S[j + 1]):
        print(j+1, j+2)
        exit()
    if (S[j] == S[j + 2]):
        print(j+1, j+3)
        exit()
else:
    print("-1 -1")