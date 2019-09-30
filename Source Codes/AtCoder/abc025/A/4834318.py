s = list(input())
n = int(input())
for i in range(5):
    for j in range(5):
        n -= 1
        if n == 0:
            print("".join([s[i], s[j]]))