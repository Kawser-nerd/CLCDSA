N = int(input())
W = [input() for _ in range(N)]
d = {}
alp = W[0][-1]
d[W[0]] = True
for i in range(1, N):
    if W[i] in d:
        print("No")
        exit()
    if alp != W[i][0]:
        print("No")
        exit()
    d[W[i]] = True
    alp = W[i][-1]
print("Yes")