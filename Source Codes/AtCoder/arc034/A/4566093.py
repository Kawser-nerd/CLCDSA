n = int(input())
a = [[int(j) for j in input().split()] for j in range(n)]
b = []

for i in range(n):
    b.append(a[i][0] + a[i][1] + a[i][2] + a[i][3] + (a[i][4] * 110)/900)

print(max(b))