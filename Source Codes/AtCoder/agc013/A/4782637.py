N = int(input())
As = list(map(int, input().split()))

count = 0
state = 0
beforeA = As[0]
for A in As:
    if A > beforeA:
        if state == 0 or state == 1:
            state = 1
        else:
            count += 1
            state = 0
    if A < beforeA:
        if state == 0 or state == 2:
            state = 2
        else:
            count += 1
            state = 0
    beforeA = A

print(count+1)