from collections import defaultdict

N = int(input())
As = sorted(map(int, input().split()), reverse=True)

prev = None
pair = []
for A in As:
    if prev == A:
        prev = None
        pair.append(A)
        if len(pair) == 2:
            break
    else:
        prev = A

if len(pair) == 2:
    print(pair[0] * pair[1])
else:
    print(0)