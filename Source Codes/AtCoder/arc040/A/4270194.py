N = int(input())
list = []
for i in range(N):
    list.append(str(input()))
R = 0
B = 0
for i in range(N):
    for j in range(N):
        if list[i][j] == "R":
            R += 1
        elif list[i][j] == "B":
            B += 1
if R == B:
    print("DRAW")
elif R > B:
    print("TAKAHASHI")
elif R < B:
    print("AOKI")