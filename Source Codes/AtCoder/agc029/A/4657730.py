S = input()
B = 0
count = 0
for s in S:
    if s == "B":
        B += 1
    elif s == "W":
        count += B
print(count)