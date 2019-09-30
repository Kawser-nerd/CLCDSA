n = input().rstrip()
keta_sum = sum([int(item) for item in n])

if int(n) % keta_sum == 0:
    print("Yes")
else:
    print("No")