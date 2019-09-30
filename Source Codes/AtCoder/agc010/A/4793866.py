N = int(input())
An = map(int, input().split())

odds = 0
evens = 0
for A in An:
    if A%2 == 0:
        evens += 1
    else:
        odds += 1

if odds%2 != 0:
    print("NO")
else:
    print("YES")