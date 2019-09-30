nums = []
X = int(input())
for i in range(1,100):
    for j in range(2,100):
        if i**j>X:
            continue
        else:
            nums.append(i**j)
print(max(nums))