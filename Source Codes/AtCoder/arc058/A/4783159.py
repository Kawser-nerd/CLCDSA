N, K = map(int, input().split())
D = [str(_) for _ in input().split()]

for i in range(N, 100000):
    S = set(list(str(i)))
    for j in S:
        if j in D:
            break
    else:
        break

print(i)