n = int(input())
arr = []
for i in range(n):
    arr.append(int(input()))

arr = set(arr)
arr = list(arr)

arr = sorted(arr)
print(arr[-2])