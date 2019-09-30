a = int(input())
b = int(input())

if 1 <= a <=100 and 1 <= b <= 100:
    if b <= a:
        if a % b == 0:
            print(0)
        elif a % b != 0:
            print(b - (a % b))
    elif a < b:
        print(b - a)