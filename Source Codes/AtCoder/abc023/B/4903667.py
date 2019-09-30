n = int(input())
S = input()
s = "b"
res = 0

for i in range(n):
    if s == S:
        print(n//2)
        break
    s = ["b","a","c"][(i+1)%3] + s + ["b","c","a"][(i+1)%3]
    res += 1
else:
    print(-1)