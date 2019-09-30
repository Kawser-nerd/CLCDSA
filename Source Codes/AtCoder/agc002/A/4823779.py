a, b = map(int, input().split())
if a > 0 or (b < 0 and (b-a)%2):
    print("Positive")
elif b < 0:
    print("Negative")
else:
    print("Zero")