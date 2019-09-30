HW = [input().split() for _ in range(2)]
for i in range(2):
    if HW[0][i] in HW[1]:
        print("YES")
        quit()

print("NO")