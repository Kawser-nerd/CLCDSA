N = int(input())
A = list(map(int, input().split(' ')))
sorted_A = sorted(A)
before = -1
pair = []
for a in sorted_A[::-1]:
    if a != before:
        before = a
    elif a == before:
        pair.append(a)
        if len(pair) == 2:
            break
        before = -1
ans = 0
if len(pair) == 2:
    ans = pair[0]*pair[1]
print(ans)