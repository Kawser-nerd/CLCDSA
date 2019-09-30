n = int(input())

a = 0
b = 0

for i in range(2, n+1):
    print('? 1', i, flush=True)
    temp = int(input())
    if temp > b:
        b = temp
        a = i

ans = 0
for i in range(1, n+1):
    if i == a:
        continue
    print('?', a , i, flush=True)
    temp = int(input())
    if temp > ans:
        ans = temp

print('!', ans)