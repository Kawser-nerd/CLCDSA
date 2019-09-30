S = list(input())
T = []
for i in S:
    if (i in T):
        print("no")
        exit()
    T.append(i)
print("yes")