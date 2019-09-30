A, B, C, D = list(map(int, input().split()))

Alice = set(range(A, B))
Bob = set(range(C, D))
print(len(Alice & Bob))