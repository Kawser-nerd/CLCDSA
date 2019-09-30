n = int(input())
s = [input() for i in range(n)]

for i in range(n):
    res = ""
    for x in s[::-1]:
        res += x[i]

    print(res)