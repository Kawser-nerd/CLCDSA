n, r = map(int,input().split())
s = list(input())

right = 0
for i in range(n):
    if s[i] == ".":
        right = i
idou = max(0, right-r+1)

nuri = 0
for i in range(n):
    if s[i] == ".":
        for j in range(r):
            if 0 <= i+j <= n-1:
                s[i+j] = "o"
        nuri += 1

print(idou + nuri)