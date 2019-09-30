n = input()
count = 1
prev = "0"
for c in n:
    if prev == c:
        count += 1
        if count == 3:
            print("Yes")
            exit()
    else:
        count = 1
    prev = c
print("No")