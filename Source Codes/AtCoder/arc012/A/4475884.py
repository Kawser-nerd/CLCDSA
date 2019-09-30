day=input()
weekday=["Mon","Tues","Wednes","Thurs","Fri"]
for i in range(len(weekday)):
    if day[:-3] == weekday[i]:
        print(5-i)
        exit()
print(0)