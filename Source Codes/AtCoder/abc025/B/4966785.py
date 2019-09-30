n,a,b=map(int,input().split())

total = 0
for i in range(n):
    s,d = input().split()
    d = int(d)
    if s == "East":
        s = -1
    else:
        s = 1
    if d < a:
        m = a
    elif d >= a and d <= b:
        m = d
    else:
        m = b
    total += m*s
if total < 0:
    print("East",abs(total))
elif total > 0:
    print("West",abs(total))
else:
    total == 0
    print(0)