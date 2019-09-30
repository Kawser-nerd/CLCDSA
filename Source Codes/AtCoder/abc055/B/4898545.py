n = int(input())
s = 1
for i in range(1,n+1):
    s = s * i
    s = s % (10**9+7)
print(s)