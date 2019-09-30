nl = list(map(int, input().split()))

s = []

for i in range(0, nl[0]):
    s.append(input())

s.sort()

print(''.join(s))