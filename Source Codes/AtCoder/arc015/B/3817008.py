N = int(input())

#initialize each kind of days.
one = 0 #???
two = 0 #???
three = 0 #??
four = 0 #???
five = 0 #??
six = 0 #???

for i in range(N):
    high,low = (float(k) for k in input().split())
    
    #check where they belong. Note that temperatures can belong to sevral kind of days.
    if high >= 35:
        one += 1
    if high >= 30 and high < 35:
        two += 1
    if high >= 25 and high < 30:
        three += 1
    if low >= 25:
        four += 1
    if low < 0 and high >= 0:
        five += 1
    if high < 0:
        six += 1


print(one,two,three,four,five,six)