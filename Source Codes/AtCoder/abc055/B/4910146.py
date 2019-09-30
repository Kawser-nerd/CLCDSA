n = int(input())

power = 1
for i in range(n):
    power = power * (i+1)%1000000007
    power %= 1000000007

print(power)