A, B = map(int, input().split())
res = "No"
for i in range(1,4):
    if (A * B * i) % 2 == 1:
        res = "Yes"
        break
print(res)