n = int(input())
m = 0

for i in range(0, n):
    money = input().split()
    if(money[1] == "JPY"):
        m += int(money[0])
    else:
        m += float(money[0]) * 380000

print(m)