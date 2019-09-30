N = str(input())
num = 0
for i in range(len(N)):
    num += int(N[i])
if int(N) % num == 0:
    print("Yes")
else:
    print("No")