yy = int(input())
mm = int(input())
dd = int(input())
y = 2014
m = 5
d = 17
day1 = 365*y+y//4-y//100+y//400+306*(m+1)//10+d-429
#print(day1)
if mm == 1 or mm == 2:
    mm += 12
    yy -= 1
day2 = 365*yy+yy//4-yy//100+yy//400+306*(mm+1)//10+dd-429
print(day1-day2)