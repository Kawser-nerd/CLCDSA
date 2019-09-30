s = input()
n = int(input())
for i in range(n):
    a,b = map(int,input().split())
    s = s[:a-1]+s[a-1:b][::-1]+s[b:]
print(s)