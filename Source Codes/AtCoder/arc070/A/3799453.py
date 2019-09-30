a = int(input())
ar = []
count = 0
i = 1
while True:
    count += i
    ar.append(i)
    if count >= a:
        break
    i += 1
print(ar[len(ar)-1])