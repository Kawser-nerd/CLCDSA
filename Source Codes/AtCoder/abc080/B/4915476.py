X = int(input())
fx = sum(map(int, list(str(X))))
if (X % fx == 0):
    print("Yes")
else:
    print("No")