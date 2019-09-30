n,l = map(int,input().split())
s = [input() for _ in range(l)]
y = input()
goal = 0
while y[goal] != 'o':
    goal += 2
goal //= 2

for i in range(n):
    now = i
    for ss in s:
        if now != 0 and ss[2 * now - 1] == '-':
            now -= 1
        elif now != n - 1 and ss[2 * now + 1] == '-':
            now += 1
    if now == goal:
        print(i + 1)
        exit()