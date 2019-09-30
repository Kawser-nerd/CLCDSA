s = list(input())

L = []
cnt = 0

for x in s:
    if x == "A" or x == "C" or x == "G" or x == "T":
        cnt += 1
    else:
        L.append(cnt)
        cnt = 0
L.append(cnt)

print(max(L))