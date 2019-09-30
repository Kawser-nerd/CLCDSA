def calc(n):
    s = "b"
    for i in range(1, n+1):
        if i % 3 == 1:
            s = "a" + s + "c"
        elif i % 3 == 2:
            s = "c" + s + "a"
        else:
            s = "b" + s + "b"
    return s

n = int(input())
s = input()
if s == calc((n - 1) // 2):
    ans = (n - 1) // 2
else:
    ans = -1
print(ans)