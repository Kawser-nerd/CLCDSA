N = int(input())
heihousu = []
s = 0
t = 0
while (t <= N):
    s += 1
    t = s**2
    heihousu.append(t)
print(heihousu[-2])