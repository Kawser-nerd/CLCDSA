n = int(input())
l = [0] * 87

l[0] = 2
l[1] = 1
for i in range(2, 87):
    l[i] = l[i-1] + l[i-2]
print(l[n])