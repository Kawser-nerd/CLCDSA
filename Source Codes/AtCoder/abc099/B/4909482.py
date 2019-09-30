a, b = map(int, input().split())

t = 0
for i in range(b-a):
    t += i

print(t - a)