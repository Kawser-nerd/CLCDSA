dif = []
for i in range(3):
    c_i = list(map(int, input().split()))
    dif.append([c_i[0] - c_i[1], c_i[1] - c_i[2]])
if dif[0] == dif[1] == dif[2]:
    print("Yes")
else:
    print("No")