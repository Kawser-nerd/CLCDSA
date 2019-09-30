a, b = map(int, input().split())
if a <= 0 <= b:
    print('Zero')
elif 0 < a or (b-a) % 2:
    print('Positive')
else:
    print('Negative')