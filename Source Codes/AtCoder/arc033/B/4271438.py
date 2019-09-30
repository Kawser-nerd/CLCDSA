N_A, N_B = map(int, input().split())

A = [int(i) for i in input().split()]
B = [int(i) for i in input().split()]

print(len(set(A) & set(B)) / len(set(A + B)))