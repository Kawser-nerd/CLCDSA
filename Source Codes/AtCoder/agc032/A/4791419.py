n = int(input())
b = list(map(int, input().split()))
a = []
count = 0

for _ in range(n):
    for i in reversed(range(len(b))):
        if b[i] == i+1:
            a.append(b.pop(i))
            count += 1
            break

if count != n:
    print(-1)
else:
    for ai in a[::-1]:
        print(ai)