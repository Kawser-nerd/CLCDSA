import math
s = list(input())
n = int(input())

a = math.floor(n/5)
b = n%5

if a != 0 and b != 0:
    print(s[a]+s[b-1])

elif a == 0 and b !=0:
    print(s[a]+s[b-1])

elif a != 0 and b == 0:
    print(s[a-1]+s[b+4])

else:
    print(s[a]+s[b])