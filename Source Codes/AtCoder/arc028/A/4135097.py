n, a, b = map(int, input().split())
t = n % (a + b)
if t > 0 and t <= a:
    print("Ant")
else:
    print("Bug")