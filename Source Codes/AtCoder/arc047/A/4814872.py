N, L = map(int, input().split())
S = input()

tab = 1
ans = 0
for s in S:
    if s == '+':
        tab += 1
    if s == '-':
        tab -= 1
    if tab > L:
        tab = 1
        ans += 1
        
print(ans)