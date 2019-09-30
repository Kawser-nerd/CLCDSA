a,b = map(int,input().split())

if a*b <= 0:
    print("Zero")
    exit()
if a > 0:
    print("Positive")
    exit()

s = abs(a) - abs(b) + 1
if s % 2 == 0:
    print("Positive")
else:
    print("Negative")