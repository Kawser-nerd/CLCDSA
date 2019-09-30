n = int(input())
array = [0, 0, 1]
for i in range(n):
    a = array[i] + array[i + 1] + array[i + 2]
    array.append(a % 10007)
print(array[n - 1])