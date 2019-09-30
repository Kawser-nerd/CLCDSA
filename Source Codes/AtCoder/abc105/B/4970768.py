N = int(input())
flag = False
for i in range(N//4+1):
    for j in range(N//7+1):
        if 4 * i + 7 * j == N:
            flag = True
if flag:
    print("Yes")
else:
    print("No")