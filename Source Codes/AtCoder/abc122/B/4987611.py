# coding: utf-8

l = list(input())
counter = 0
atcorder = []


for i in range(len(l)):
    if(l[i] == "A" or l[i] == "T" or l[i] == "G" or l[i] == "C"):
        counter += 1
        atcorder.append(counter)
        continue

    counter = 0


if(len(atcorder) != 0):
    print(max(atcorder))
else:
    print("0")