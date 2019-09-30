y = int(input())
m = int(input())
d = int(input())

if m == 1:
    m = 13
    y = y - 1

if m == 2:
    m = 14
    y = y - 1
    
day1 = 365 * y + int(y/4) - int(y/100) + int(y/400) + int(306*(m + 1) / 10) + d - 429

y = 2014
m = 5
d = 17 

day2 = 365 * y + int(y/4) - int(y/100) + int(y/400) + int(306*(m + 1) / 10) + d - 429

print(day2 - day1)