n, a, b = map(int, input().split())

# ????????????????
# print(list("python")) ['p', 'y', 't', 'h', 'o', 'n']

ans = 0
for i in range(n+1):
    if a <= sum(list(map(int,list(str(i))))) <= b:
        ans += i
print(ans)