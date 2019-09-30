y,m,d = int(input()),int(input()),int(input())
if m == 1:
    y -= 1
    m = 13
elif m == 2:
    y -= 1
    m = 14
#print(y,m,d)
ANS = 365*y + int(y/4) - int(y/100) + int(y/400) + int((306*(m+1))/10) + d - 429
#print(ANS)

y,m,d = 2014,5,17
ANS2 = 365*y + int(y/4) - int(y/100) + int(y/400) + int((306*(m+1))/10) + d - 429
#print(ANS2)
print(ANS2 - ANS)