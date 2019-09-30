N = int(input())
a = [int(_) for _ in input().split()]
List = [0]*(10**5+1)
ans = 0

for i in a:
    if i > 10**5:
        ans += 1
    else:
        List[i] += 1

for i in range(1, 10**5+1):
    if List[i] >= i:
        ans += List[i] - i
    else:
        ans += List[i]

print(ans)