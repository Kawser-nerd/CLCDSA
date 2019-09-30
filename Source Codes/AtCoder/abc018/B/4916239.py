#17
s = input()
n = int(input())
for i in range(n):
    a,b = map(int, input().split())
    temp = s[:a-1]
    for j in reversed(range(a-1,b)):
        temp += s[j]
    temp += s[b:]
    s = temp
print(s)