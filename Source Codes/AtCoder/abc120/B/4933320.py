A, B, K = map(int, input().split())
counter = 0

for i in reversed(range(0, min(A, B)+1)):
    if A % i == 0 and B % i == 0:
        counter += 1
    if counter == K:
        print(i)
        break