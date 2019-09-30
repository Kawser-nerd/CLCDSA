s = input()
n = int(input())
for i in range(n):
    l, m = map(int, input().split())
    r = ''
    if l > 1:
        r += s[0:l-1]
    r += s[l-1:m][::-1]
    if m < len(s):
        r += s[m:]
    s = r
print(s)