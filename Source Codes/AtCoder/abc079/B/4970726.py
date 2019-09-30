N = int(input())
ryukasu = [2, 1]
for i in range(2, N+1):
    ryukasu.append(ryukasu[i - 1] + ryukasu[i - 2])
print(ryukasu[-1])