def Day(y, m, d):
    if m == 1:
        y -= 1
        m = 13
    elif m == 2:
        y -= 1
        m = 14

    return 365*y + y//4 - y//100 + y//400 + 306*(m+1)//10 + d - 429


y = int(input())
m = int(input())
d = int(input())

print(Day(2014, 5, 17) - Day(y, m, d))