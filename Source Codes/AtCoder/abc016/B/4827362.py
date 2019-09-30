a, b, c = map(int, input().split())
p = a+b
m = a-b
if ((p == c) & (m != c)):
    print("+")
elif ((p != c) & (m == c)):
    print("-")
elif ((p == c) & (m == c)):
    print('?')
else:
    print("!")