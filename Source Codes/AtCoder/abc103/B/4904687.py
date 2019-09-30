S = list(input())
T = list(input())
for i in range(len(S)):
    if (S == T):
        print("Yes")
        exit()
    S.insert(0, S[-1])
    del S[-1]
print("No")