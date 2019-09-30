s = input().split()
a = int(s[0])
b = int(s[1])
c = int(s[2])
 
if 1 <= a and b and c <= 100:
    if a < b < c or c < b < a or a == b == c:
        print(b)
    elif a < c < b or b < c < a:
        print(c)
    elif b < a < c or c < a < b:
        print(a)
    elif a == b:
        print(a)
    elif a == c or b == c:
        print(c)