n = int(input())
s = input()
num = 0
d = {'A': 4, 'B': 3, 'C': 2, 'D': 1, 'F': 0}
for i in s:
    num += d[i]

print(num / n)