n = int(input())
avg = 0
for i in range(1, n+1):
    avg += i
print(int(avg/n*10000))