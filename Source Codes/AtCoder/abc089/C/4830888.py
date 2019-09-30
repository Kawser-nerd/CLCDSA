n = int(input())
c = {"M": 0, "A": 0, "R": 0, "C": 0, "H": 0}
march = "MARCH"

for i in range(0, n):
    s = input()[0]
    if s == "M" or s == "A" or s == "R" or s == "C" or s == "H":
        c[s] += 1

s = 0
for i in range(0, 5):
    for j in range(i + 1, 5):
        for k in range(j + 1, 5):
            s += c[march[i]] * c[march[j]] * c[march[k]]

print(s)