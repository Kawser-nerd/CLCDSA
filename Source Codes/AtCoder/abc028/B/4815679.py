n = list(input())

a = [0,0,0,0,0,0]

for i in range(len(n)):
    if n[i] == "A":
        a[0] += 1
    elif n[i] == "B":
        a[1] += 1
    elif n[i] == "C":
        a[2] += 1
    elif n[i] == "D":
        a[3] += 1
    elif n[i] == "E":
        a[4] += 1
    elif n[i] == "F":
        a[5] += 1

print(" ".join(map(str,a)))