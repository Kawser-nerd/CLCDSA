n = int(input())
s = input()

if n % 2 == 0:
    print(-1)
    exit()

m = (n-1) // 2

t = 'b'

for i in range(m):
    if i % 3 == 0:
        t = 'a' + t + 'c'
    elif i % 3 == 1:
        t = 'c' + t + 'a'
    else:
        t = 'b' + t + 'b'

if s == t:
    print(m)
else:
    print(-1)