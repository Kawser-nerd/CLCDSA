n = int(input())
h = input().split()
h = [int(_h) for _h in h]

counter = h[0]

for i in range(1, n):
    if h[i] > h[i - 1]:
        counter += h[i] - h[i - 1]
print(counter)