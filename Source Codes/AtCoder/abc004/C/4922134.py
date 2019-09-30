n = int(input())

d = (n // 5) % 6
m = n % 5

c = [str(i+1) for i in range(6)]

c = c[d:] + c[:d]

for i in range(m):
    c[i], c[i+1] = c[i+1], c[i]

print(''.join(c))