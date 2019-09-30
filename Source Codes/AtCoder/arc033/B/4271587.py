N_A, N_B = map(int, input().split())

A = set([i for i in input().split()])
B = set([i for i in input().split()])

print(len(A & B) / len(A | B))