nums = []
anss = []
for i in range(1, int(input())+1):
    count = 0
    while i%2 == 0:
        i //= 2
        count += 1
    anss.append(count)
print(anss.index(max(anss))+1)