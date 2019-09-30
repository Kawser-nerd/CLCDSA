n = int(input())
i = 0
k = 10000
sum = 0
while i < n :
    sum += k / n
    k += 10000
    i += 1
print(int(sum))